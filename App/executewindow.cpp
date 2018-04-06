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
    problemSolver->Solve();
}

ExecuteWindow::~ExecuteWindow()
{
    delete ui;

}
