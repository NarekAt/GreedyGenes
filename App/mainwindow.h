#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "additionaloptionswindow.h"
#include "problem.h"

class Problem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

    void on_nextButton_clicked();

private:
    Ui::MainWindow *ui;
    AdditionalOptionsWindow *addOptionsUI;
    Problem *problem;
};

#endif // MAINWINDOW_H
