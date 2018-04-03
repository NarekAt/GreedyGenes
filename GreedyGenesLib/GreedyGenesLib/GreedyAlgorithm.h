#pragma once

#include "GreedySDK.h"
#include "Matroid.h"
#include "GreedyStrategy.h"

#include <memory>

template <class Params>
class GreedyAlgorithm
{
public:
    GreedyAlgorithm(IMatroidPtr<Params> matroid, GreedyStrategyPtr<Params> strategy, Params& params)
        : m_matroid(matroid)
        , m_greedyStrategy(strategy)
        , m_params(params)
    {}

    GreedyAlgorithm() = default;

    void Solve()
    {
        m_greedyStrategy->Init(m_matroid, m_params);

        m_greedyStrategy->Solve();
    }

    typename Params::ResultType GetResults()
    {
        return m_greedyStrategy->GetResults();
    }

protected:
    IMatroidPtr<Params>       m_matroid;
    GreedyStrategyPtr<Params> m_greedyStrategy;
    Params m_params;
};
