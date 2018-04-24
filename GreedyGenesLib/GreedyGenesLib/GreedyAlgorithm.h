#pragma once

#include "GreedySDK.h"
#include "Algorithm.h"
#include "Matroid.h"
#include "GreedyStrategy.h"

#include <memory>

template <class Params>
class GreedyAlgorithm : public IAlgorithm
{
public:
    GreedyAlgorithm(GreedyStrategyPtr<Params> strategy)
        : m_matroid(strategy->GetProblemMatroid())
        , m_greedyStrategy(strategy)
        , m_params(strategy->GetParams())
    {}

    GreedyAlgorithm() = default;

    void Solve() override
    {
        m_greedyStrategy->Solve();
    }

    virtual typename Params::ResultType GetResults()
    {
        return m_greedyStrategy->GetResults();
    }

    std::string StoreResultsInFile() override
    {
        return "";
    }

protected:
    IMatroidPtr<Params>       m_matroid;
    GreedyStrategyPtr<Params> m_greedyStrategy;
    Params m_params;
};

template <class Params>
using GreedyAlgorithmPtr = std::shared_ptr<GreedyAlgorithm<Params>>;
