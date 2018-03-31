#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "GreedySDK.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    auto dir = QFileDialog::getExistingDirectory(this, tr("Select Path"));

    ui->filePath->setText(dir);
}

void MainWindow::on_commandLinkButton_clicked()
{

}
