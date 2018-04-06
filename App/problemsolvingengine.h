#ifndef PROBLEMSOLVINGENGINE_H
#define PROBLEMSOLVINGENGINE_H

#include <QString>
#include <QErrorMessage>
#include "problem.h"
#include "enumconverters.h"
#include "GreedyAlgorithmFactory.h"
//#include "GeneticAlgorithmFactory.h"

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

        auto& ga = GreedyAlgorithmFactory::GetInstance();
    }

private:
    Problem* m_problem;
    QErrorMessage* m_errMsg;
};

#endif // PROBLEMSOLVINGENGINE_H
