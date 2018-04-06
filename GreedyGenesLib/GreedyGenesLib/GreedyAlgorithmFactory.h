#pragma once
#include "GreedyAlgorithm.h"

class foo
{
public:
    void f();

};

class GreedyAlgorithmFactory
{
public:
    static GreedyAlgorithmFactory& GetInstance();

    template <class Params>
    GreedyAlgorithmPtr<Params> CreateAlgorithm(ProblemType problem,
        const Params& params, const std::string& inputDataFile);

    /// prevent copying
    GreedyAlgorithmFactory(GreedyAlgorithmFactory const&) = delete;
    void operator=(GreedyAlgorithmFactory const&) = delete;

    /// prevent moving
    GreedyAlgorithmFactory(GreedyAlgorithmFactory const&&) = delete;
    void operator=(GreedyAlgorithmFactory const&&) = delete;

protected:
    GreedyAlgorithmFactory() = default;
};

template<class Params>
inline GreedyAlgorithmPtr<Params> GreedyAlgorithmFactory::CreateAlgorithm(ProblemType problem, const Params& p, const std::string& inputDataFile)
{
    return nullptr;
}
