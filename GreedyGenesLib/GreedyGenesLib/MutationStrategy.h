#pragma once
#include "GeneticSDK.h"

class MutatationStrategy
{
public:
    virtual void Mutate(Generation& gen) = 0;

    virtual ~MutatationStrategy() = default;
};

using MutatationStrategyPtr = std::shared_ptr<MutatationStrategy>;
