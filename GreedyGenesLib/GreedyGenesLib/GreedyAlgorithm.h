#pragma once

#include "GreedyGenesSDK.h"
#include "Algorithm.h"
#include "Matroid.h"
#include "GreedyStrategy.h"

#include <memory>

template <class Params>
class GreedyAlgorithm : public IAlgorithm
{
public:
    GreedyAlgorithm(IMatroidPtr<Params> matroid, GreedyStrategyPtr<Params> strategy)
        : m_matroid(matroid)
        , m_greedyStrategy(strategy)
    {}

    GreedyAlgorithm() = default;

    void Solve() override
    {
        m_greedyStrategy->Init(m_matroid);

        m_greedyStrategy->Solve();
    }

protected:
    IMatroidPtr<Params>       m_matroid;
    GreedyStrategyPtr<Params> m_greedyStrategy;
};
