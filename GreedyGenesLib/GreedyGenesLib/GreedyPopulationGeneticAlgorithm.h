#pragma once

#include "GreedyAlgorithm.h"
#include "IncrementalGeneticAlgorithm.h"

template <class Params>
class GreedyPopulationGeneticAlgorithm : public IncrementalGeneticAlgorithm<Params>
{
    using Base = IncrementalGeneticAlgorithm<Params>;

public:
    GreedyPopulationGeneticAlgorithm(CrossoverStrategyPtr crossover,
        MutatationStrategyPtr mutation,
        InversionStrategyPtr inversion,
        FitnessEvaluationStrategyPtr fitness,
        IResultWritterPtr resWritter,
        size_t numOfGenerations,
        size_t numOfChromosomesToReplace)
        : Base(crossover, mutation, inversion, fitness, resWritter, numOfGenerations, numOfChromosomesToReplace)
    {}

    GreedyPopulationGeneticAlgorithm() = default;

    void SetGreedyAlgorithm(GreedyAlgorithm<Params>& algo);

protected:
    void InitialGeneration() override;

private:
    GreedyAlgorithm<Params> m_greedy;
};

// Impl
template<class Params>
inline void GreedyPopulationGeneticAlgorithm<Params>::InitialGeneration()
{
    m_greedy.Solve();

    auto result = m_greedy.GetResults();

    for (size_t i = 0; i != Base::m_numberOfGenerations; ++i)
    {
        std::random_shuffle(std::begin(result), std::end(result));

        Base::m_generation.push_back(std::make_shared<Chromosome>(result));
    }
}

template<class Params>
inline void GreedyPopulationGeneticAlgorithm<Params>::SetGreedyAlgorithm(GreedyAlgorithm<Params>& algo)
{
    m_greedy = algo;
}
