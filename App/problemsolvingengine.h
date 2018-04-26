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
    {
        m_errMsg->setWindowFlags(Qt::WindowStaysOnTopHint);
    }

    ~ProblemSolvingEngine()
    {
        delete m_problem;
        delete m_errMsg;
    }

    QString GetResultFile()
    {
        return m_resultFile;
    }

    ProblemType GetProblemType()
    {
        return m_prType;
    }

    void Solve()
    {
        if (!EnumConverter::FromString(m_problem->m_problem, m_prType))
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
        for (auto it = m_problem->m_geneticAlgOptions.begin(); it != m_problem->m_geneticAlgOptions.end(); ++it)
        {
            additionalOptions.insert({ it.key().toStdString(), it.value().toStdString() });
        }

        auto algo = OptimizationsAlgorithmFactory::GetInstance().CreateAlgorithm(
                    m_prType, m, m_problem->m_inputDir.toStdString(), additionalOptions);

        if (algo == nullptr)
        {
            // TODO: error handling
            return;
        }

        algo->Solve();
        m_resultFile = QString(algo->StoreResultsInFile().c_str());
    }

private:
    Problem* m_problem;
    QErrorMessage* m_errMsg;
    QString m_resultFile;

    ProblemType m_prType;
};

#endif // PROBLEMSOLVINGENGINE_H
