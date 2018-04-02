#pragma once

#include "GeneticSDK.h"

class InversionStrategy
{
public:
    virtual void Inverse(Generation& gen) = 0;

    virtual ~InversionStrategy() = default;
};

using InversionStrategyPtr = std::shared_ptr<InversionStrategy>;
