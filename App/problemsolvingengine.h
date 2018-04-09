#ifndef PROBLEMSOLVINGENGINE_H
#define PROBLEMSOLVINGENGINE_H

#include <QString>
#include <QtWidgets>
#include <QErrorMessage>
#include <functional>
#include "problem.h"
#include "enumconverters.h"
#include "optimizationsalgorithmfactory.h"
#include <iostream>
#include <QtConcurrent/QtConcurrent>

class ProblemSolvingEngine
{
public:
    ProblemSolvingEngine(Problem* p)
        : m_problem(p)
        , m_errMsg(new QErrorMessage())
        , m_progressDialog(new QProgressDialog())
    {
        m_errMsg->setWindowFlags(Qt::WindowStaysOnTopHint);

        m_progressDialog->setWindowFlags(Qt::WindowStaysOnTopHint);

        m_progressDialog->setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));

        QObject::connect(&m_futureWatcher, &QFutureWatcher<void>::finished, m_progressDialog, &QProgressDialog::reset);
        QObject::connect(m_progressDialog, &QProgressDialog::canceled, &m_futureWatcher, &QFutureWatcher<void>::cancel);
        QObject::connect(&m_futureWatcher,  &QFutureWatcher<void>::progressRangeChanged, m_progressDialog, &QProgressDialog::setRange);
        QObject::connect(&m_futureWatcher, &QFutureWatcher<void>::progressValueChanged,  m_progressDialog, &QProgressDialog::setValue);
    }

    ~ProblemSolvingEngine()
    {
        delete m_problem;
        delete m_errMsg;
        delete m_progressDialog;
    }

    void Solve()
    {
        ProblemType prType;
        if (!EnumConverter::FromString(m_problem->m_problem, prType))
        {
            m_errMsg->showMessage("Invalid type of problem to solve", "Input error");
            return;
        }

        Method m;
        if (!EnumConverter::FromString(m_problem->m_method, m))
        {
            m_errMsg->showMessage("Invalid solving method is specified", "Input error");
            return;
        }

        std::map<std::string, std::string> additionalOptions;
        for (auto it = m_problem->m_greedyAlgOptions.begin(); it != m_problem->m_greedyAlgOptions.end(); ++it)
        {
            additionalOptions.insert({ it.key().toStdString(), it.value().toStdString() });
        }
        auto algo = OptimizationsAlgorithmFactory::GetInstance().CreateAlgorithm(
                    prType, m, m_problem->m_inputDir.toStdString(), additionalOptions);

        if (algo == nullptr)
        {
            // TODO: error handling
            return;
        }
        QVector<int> vector;
        for (int i = 0; i < 20; ++i)
            vector.append(i);

        std::function<void(int&)> spin = [algo](int &iteration)
        {
            algo->Solve();

            qDebug() << "iteration" << iteration << "in thread" << QThread::currentThreadId();
        };

        m_futureWatcher.setFuture(QtConcurrent::map(vector, spin));

        m_progressDialog->exec();
        m_futureWatcher.waitForFinished();
    }

private:
    Problem* m_problem;
    QErrorMessage* m_errMsg;
    QProgressDialog* m_progressDialog;

    QFutureWatcher<void> m_futureWatcher;
};

#endif // PROBLEMSOLVINGENGINE_H
