#ifndef PROBLEMSOLVINGENGINE_H
#define PROBLEMSOLVINGENGINE_H

#include "QString"
#include "problem.h"

class ProblemSolvingEngine
{
public:
    ProblemSolvingEngine(Problem* p)
        : m_problem(p)
    {}

    void Solve()
    {

    }

private:
    Problem* m_problem;
};

#endif // PROBLEMSOLVINGENGINE_H
