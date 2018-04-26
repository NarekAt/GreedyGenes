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
    problemSolver->Solve();

    ui->resultsButton->setEnabled(true);
}

void ExecuteWindow::on_resultsButton_clicked()
{
    auto file = problemSolver->GetResultFile();

    QDesktopServices::openUrl(QUrl(QDir::currentPath() + "/" + file));
}
