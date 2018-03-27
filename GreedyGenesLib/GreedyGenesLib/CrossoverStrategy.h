#pragma once

#include <memory>

class CrossoverStrategy
{
public:
    virtual void Crossover() = 0;

    virtual ~CrossoverStrategy() = default;
};


using CrossoverStrategyPtr = std::shared_ptr<CrossoverStrategy>;