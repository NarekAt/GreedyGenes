#pragma once

#include "GeneticSDK.h"
#include "Algorithm.h"
#include "ReproductionStrategy.h"
#include "CrossoverStrategy.h"
#include "MutationStrategy.h"

class GeneticAlgorithm : public IAlgorithm
{
public:
    void Solve();
    ChromosomePtr GetBestChromosome();

protected:
    virtual void InitializeGeneration() = 0;
    virtual void IncrementGenerations() = 0;
    virtual void MoreGenerations() = 0;

protected:
    ReproductionStrategyPtr m_reproduction;
    CrossoverStrategyPtr    m_crossover;
    MutatationStrategyPtr   m_mutation;
};
