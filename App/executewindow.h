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

private:
    Ui::ExecuteWindow *ui;

    ProblemSolvingEngine *problemSolver;
};

#endif // EXECUTEWINDOW_H
