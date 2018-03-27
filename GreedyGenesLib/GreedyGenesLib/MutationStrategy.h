#pragma once
#include <memory>

class MutatationStrategy
{
public:
    virtual void Mutate() = 0;

    virtual ~MutatationStrategy() = default;
};

using MutatationStrategyPtr = std::shared_ptr<MutatationStrategy>;
