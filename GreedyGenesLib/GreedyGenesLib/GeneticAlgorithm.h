#pragma once

#include "GeneticSDK.h"
#include "Algorithm.h"
#include "CrossoverStrategy.h"
#include "MutationStrategy.h"
#include "InversionStrategy.h"
#include "FitnessEvaluationStrategy.h"
#include <algorithm>

template <class Params>
class GeneticAlgorithm : public IAlgorithm
{
public:
    GeneticAlgorithm() = default;

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

    auto ChooseParents()
    {
        std::sort(m_generation.begin(), m_generation.end(),
            [](ChromosomePtr ch1, ChromosomePtr ch2)
            {
                return ch1->GetFitness() > ch2->GetFitness();
            });

        std::pair<ChromosomePtr, ChromosomePtr> parents;
        parents.first = m_generation[0];

        auto it = std::find_if(m_generation.begin(), m_generation.end(),
            [](ChromosomePtr ch)
            {
                return ch->GetFitness() != parents.first;
            });

        parents.second = (it != m_generation.end() ? *it : parents.first);

        return parents;
    }

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
