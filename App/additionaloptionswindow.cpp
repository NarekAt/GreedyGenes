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
    problem->m_geneticAlgOptions.insert("Mutation Rate", QString::number(ui->mutationRate->value()));
    problem->m_geneticAlgOptions.insert("Inversion Rate", QString::number(ui->inversionRate->value()));
    problem->m_geneticAlgOptions.insert("Num of Generation", QString::number(ui->numOfGenerations->value()));

    execWin->TransferData(problem);

    this->hide();

    execWin->show();
}
