#pragma once

#include "GeneticSDK.h"
#include "Algorithm.h"
#include "CrossoverStrategy.h"
#include "MutationStrategy.h"
#include "InversionStrategy.h"
#include "FitnessEvaluationStrategy.h"

template <class Params>
class GeneticAlgorithm : public IAlgorithm
{
public:
    GeneticAlgorithm(CrossoverStrategyPtr crossover,
        MutatationStrategyPtr mutation,
        InversionStrategyPtr inversion,
        FitnessEvaluationStrategyPtr<Params> fitness)
        : m_crossover(crossover)
        , m_mutation(mutation)
        , m_inversion(inversion)
        , m_fitness(fitness)
    {}

    void Solve()
    {
        InitialGeneration();

        m_fitness->Evaluate(m_generation);

        for (size_t i = 0; i != m_numberOfGenerations; ++i)
        {
            for (size_t j = 0; j != m_numberOfOffsprings; ++j)
            {
                auto parents = ChooseParents();

                m_offsprings[j] = (m_crossover->Crossover(parents.first, parents.second)).back();

                m_mutation->Mutate(m_generation);

                m_inversion->Inverse(m_generation);

                m_fitness->Evaluate(m_generation);
            }
            IncrementGenerations();
        }
    }

    ChromosomePtr GetBestChromosome();

protected:
    virtual void InitialGeneration() = 0;
    virtual void IncrementGenerations() = 0;

    std::pair<ChromosomePtr, ChromosomePtr> ChooseParents();

protected:
    CrossoverStrategyPtr         m_crossover;
    MutatationStrategyPtr        m_mutation;
    InversionStrategyPtr         m_inversion;
    FitnessEvaluationStrategyPtr<Params> m_fitness;

    Generation m_generation;
    Generation m_offsprings;

    size_t m_numberOfGenerations;
    size_t m_numberOfOffsprings;
};
