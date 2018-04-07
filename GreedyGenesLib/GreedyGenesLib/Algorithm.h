#pragma once

#include <string>
#include <memory>

class IAlgorithm
{
public:
    virtual void Solve() = 0;

    virtual std::string StoreResultsInFile() = 0;

    virtual ~IAlgorithm() = default;
};

using AlgorithmPtr = std::shared_ptr<IAlgorithm>;
