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

    ui->greedyBox->setEnabled(false);
    ui->geneticGroupBox->setEnabled(false);
}

AdditionalOptionsWindow::~AdditionalOptionsWindow()
{
    delete ui;
    delete execWin;
}

void AdditionalOptionsWindow::TransferData(Problem* p)
{
    problem = p;

    Method m;
    EnumConverter::FromString(problem->m_method, m);
    if(m == Method::GREEDY)
    {
        ui->greedyBox->setEnabled(true);
    }
    else
    {
        ui->geneticGroupBox->setEnabled(true);
    }
}

void AdditionalOptionsWindow::on_commandLinkButton_clicked()
{
    problem->m_geneticAlgOptions.insert("Mutation Rate", QString::number(ui->mutationRate->value()));
    problem->m_geneticAlgOptions.insert("Inversion Rate", QString::number(ui->inversionRate->value()));
    problem->m_geneticAlgOptions.insert("Num of Generation", QString::number(ui->numOfGenerations->value()));
    problem->m_greedyAlgOptions.insert("k number", QString::number(ui->kSpinBox->value()));
    problem->m_greedyAlgOptions.insert("alpha number", QString::number(ui->alphaSpinBox->value()));

    execWin->TransferData(problem);

    this->hide();

    execWin->show();
}
