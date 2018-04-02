#pragma once

#include "GeneticSDK.h"
#include "GreedySDK.h"

template <class ProblemParams>
class FitnessEvaluationStrategy
{
public:
    FitnessEvaluationStrategy(IMatroidPtr<ProblemParams> problemMatroid)
        : m_problem(problemMatroid)
    {}

    virtual void Evaluate(Generation&) = 0;

    virtual ~FitnessEvaluationStrategy() = default;

protected:
    IMatroidPtr<ProblemParams> m_problem;
};

template <class Params>
using FitnessEvaluationStrategyPtr = std::shared_ptr<FitnessEvaluationStrategy<Params>>;
