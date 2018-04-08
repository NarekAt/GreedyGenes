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
        FitnessEvaluationStrategyPtr fitness,
        size_t numOfGenerations)
        : m_crossover(crossover)
        , m_mutation(mutation)
        , m_inversion(inversion)
        , m_fitness(fitness)
        , m_numberOfGenerations(numOfGenerations)
    {}

    void Solve() override
    {
        InitialGeneration();

        m_fitness->Evaluate(m_generation);

        for (size_t i = 0; i != m_numberOfGenerations; ++i)
        {
            auto parents = ChooseParents();

            auto offSprings = m_crossover->Crossover(parents.first, parents.second);
            m_generation.insert(std::end(m_generation), std::begin(offSprings), std::end(offSprings));

            m_mutation->Mutate(m_generation);

            m_inversion->Inverse(m_generation);

            m_fitness->Evaluate(m_generation);

            IncrementGenerations();
        }
    }

    std::string StoreResultsInFile() override
    {
        return "";
    }

    ChromosomePtr GetBestChromosome()
    {
        auto it = std::max_element(std::begin(m_generation), std::end(m_generation),
            [](ChromosomePtr ch1, ChromosomePtr ch2)
            {
                return ch1->GetFitness() < ch2->GetFitness();
            });

        return *it;
    }

protected:
    virtual void InitialGeneration() = 0;
    virtual void IncrementGenerations() = 0;

private:
    std::pair<ChromosomePtr, ChromosomePtr> ChooseParents()
    {
        std::sort(m_generation.begin(), m_generation.end(),
            [](ChromosomePtr ch1, ChromosomePtr ch2)
            {
                return ch1->GetFitness() > ch2->GetFitness();
            });

        std::pair<ChromosomePtr, ChromosomePtr> parents;
        parents.first = m_generation[0];

        auto it = std::find_if(m_generation.begin(), m_generation.end(),
            [&](ChromosomePtr ch)
            {
                return ch->GetFitness() != parents.first->GetFitness();
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

    size_t m_numberOfGenerations;
};

template <class Params>
using GeneticAlgorithmPtr = std::shared_ptr<GeneticAlgorithm<Params>>;
