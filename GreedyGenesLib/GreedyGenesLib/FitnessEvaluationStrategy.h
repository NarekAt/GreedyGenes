#pragma once

#include "GeneticSDK.h"

class FitnessEvaluationStrategy
{
public:
    virtual void Evaluate(Generation&) = 0;

    virtual ~FitnessEvaluationStrategy() = default;
};

using FitnessEvaluationStrategyPtr = std::shared_ptr<FitnessEvaluationStrategy>;
