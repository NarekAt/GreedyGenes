#pragma once

#include <memory>
#include "Matroid.h"

template <class Params>
class GreedyStrategy
{
public:
    using MatroidPtr = IMatroidPtr<Params>;

    virtual MatroidPtr GetProblemMatroid() = 0;
    virtual Params& GetParams() = 0;

    virtual void Solve() = 0;
    virtual typename Params::ResultType GetResults() = 0;
    virtual std::string StoreResults() = 0;

    virtual ~GreedyStrategy() = default;
};

template <class Params>
using GreedyStrategyPtr = std::shared_ptr<GreedyStrategy<Params>>;
