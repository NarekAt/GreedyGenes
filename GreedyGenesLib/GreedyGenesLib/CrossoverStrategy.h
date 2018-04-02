#pragma once

#include "GeneticSDK.h"

class CrossoverStrategy
{
public:
    virtual std::vector<ChromosomePtr> Crossover(ChromosomePtr parent1, ChromosomePtr parent2) = 0;

    virtual ~CrossoverStrategy() = default;
};


using CrossoverStrategyPtr = std::shared_ptr<CrossoverStrategy>;