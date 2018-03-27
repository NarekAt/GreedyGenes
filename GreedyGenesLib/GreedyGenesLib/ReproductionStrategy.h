#pragma once
#include <memory>

class ReproductionStrategy
{
public:
    virtual void Reproduce() = 0;

    virtual ~ReproductionStrategy() = default;
};

using ReproductionStrategyPtr = std::shared_ptr<ReproductionStrategy>;
