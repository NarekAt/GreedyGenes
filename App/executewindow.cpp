#include "executewindow.h"
#include "ui_executewindow.h"

ExecuteWindow::ExecuteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExecuteWindow)
{
    ui->setupUi(this);
}

void ExecuteWindow::TransferData(Problem* p)
{
    problemSolver = new ProblemSolvingEngine(p);
}

ExecuteWindow::~ExecuteWindow()
{
    delete ui;
}

void ExecuteWindow::on_solveButton_clicked()
{
    auto solve = [this]()
    {
        problemSolver->Solve();
    };

    auto res = std::async(std::launch::async, solve);

    try
    {
        res.get();
    }
    catch(...)
    {
        // Error handling

        return;
    }

    ui->resultsButton->setEnabled(true);
}

void ExecuteWindow::on_resultsButton_clicked()
{
    QString file;

    auto getRes = [&]()
    {
        file = problemSolver->GetResultFile();
    };

    auto res = std::async(std::launch::async, getRes);

    try
    {
        res.get();
    }
    catch(...)
    {
        // Error handling
        return;
    }

    // FIXME: Temp hack
    if (problemSolver->GetProblemType() == ProblemType::TRAVELING_SALESMAN)
    {
        file = "tsp.out";
    }

    QDesktopServices::openUrl(QUrl(QDir::currentPath() + "/" + file));
}
