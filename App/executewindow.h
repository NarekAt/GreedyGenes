#ifndef EXECUTEWINDOW_H
#define EXECUTEWINDOW_H

#include <QMainWindow>

#include "problemsolvingengine.h"

namespace Ui {
class ExecuteWindow;
}

class ExecuteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExecuteWindow(QWidget *parent = 0);
    ~ExecuteWindow();

    void TransferData(Problem* p);

private slots:
  void on_solveButton_clicked();

  void on_resultsButton_clicked();

private:
    Ui::ExecuteWindow *ui;

    ProblemSolvingEngine *problemSolver;
};

#endif // EXECUTEWINDOW_H
