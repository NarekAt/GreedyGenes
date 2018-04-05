#ifndef ADDITIONALOPTIONSWINDOW_H
#define ADDITIONALOPTIONSWINDOW_H

#include <QMainWindow>
#include "problem.h"

class ExecuteWindow;

namespace Ui {
class AdditionalOptionsWindow;
}

class AdditionalOptionsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdditionalOptionsWindow(QWidget *parent = 0);
    ~AdditionalOptionsWindow();

    void TransferData(Problem* p);

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::AdditionalOptionsWindow *ui;
    ExecuteWindow *execWin;
    Problem *problem;
};

#endif // ADDITIONALOPTIONSWINDOW_H
