#pragma once

#include "GeneticAlgorithm.h"

template <class Params>
class IncrementalGeneticAlgorithm : public GeneticAlgorithm<Params>
{
    using Base = GeneticAlgorithm<Params>;

public:
    IncrementalGeneticAlgorithm(CrossoverStrategyPtr crossover,
        MutatationStrategyPtr mutation,
        InversionStrategyPtr inversion,
        FitnessEvaluationStrategyPtr<Params> fitness,
        size_t numOfGenerations,
        size_t numOfChromosomesToReplace)
        : Base(crossover, mutation, inversion, fitness, numOfGenerations)
        , m_numOfChromosomesToReplace(numOfChromosomesToReplace)
    {}

    IncrementalGeneticAlgorithm() = default;

protected:
    void InitialGeneration() override;
    void IncrementGenerations() override;

private:
    size_t m_numOfChromosomesToReplace;
};


// Impl
template<class Params>
inline void IncrementalGeneticAlgorithm<Params>::InitialGeneration()
{
}

template<class Params>
inline void IncrementalGeneticAlgorithm<Params>::IncrementGenerations()
{
    std::sort(m_generation.begin(), m_generation.end(),
        [](ChromosomePtr ch1, ChromosomePtr ch2)
        {
            return ch1->GetFitness() > ch2->GetFitness();
        });

    // replace only specified number of chromosomes
    // at the end of each generation,
    // thus allowing majority of chromosomes to survive
    while (m_numOfChromosomesToReplace && !m_generation.empty())
    {
        m_generation.pop_back();

        --m_numOfChromosomesToReplace;
    }
}
