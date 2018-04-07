#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "qfiledialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    problem(new Problem())
{
    ui->setupUi(this);
    addOptionsUI = new AdditionalOptionsWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addOptionsUI;
    delete problem;
}

void MainWindow::on_toolButton_clicked()
{
    const QString path = QFileDialog::getOpenFileName(this, tr("Select an input file"));

    ui->filePath->setText(path);
}

void MainWindow::on_nextButton_clicked()
{
    problem->m_inputDir = ui->filePath->displayText();
    problem->m_method = ui->selectMethodComboBox->currentText();
    problem->m_problem = ui->selectAlgComboBox->currentText();

    this->hide();

    addOptionsUI->TransferData(problem);
    addOptionsUI->show();
}
