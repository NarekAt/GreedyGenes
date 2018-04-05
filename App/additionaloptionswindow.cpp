#include "additionaloptionswindow.h"
#include "ui_additionaloptionswindow.h"
#include "executewindow.h"

AdditionalOptionsWindow::AdditionalOptionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdditionalOptionsWindow),
    problem(new Problem())
{
    ui->setupUi(this);
    execWin = new ExecuteWindow(this);
}

AdditionalOptionsWindow::~AdditionalOptionsWindow()
{
    delete ui;
    delete execWin;
}

void AdditionalOptionsWindow::TransferData(Problem* p)
{
    problem = p;
}

void AdditionalOptionsWindow::on_commandLinkButton_clicked()
{
    problem->m_geneticAlgOptions.insert("Mutation Rate", ui->mutationRate->value());
    problem->m_geneticAlgOptions.insert("Inversion Rate", ui->inversionRate->value());
    problem->m_geneticAlgOptions.insert("Num of Generation", ui->numOfGenerations->value());

    execWin->TransferData(problem);

    this->hide();

    execWin->show();
}
