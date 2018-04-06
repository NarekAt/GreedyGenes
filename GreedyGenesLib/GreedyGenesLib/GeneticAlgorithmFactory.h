#pragma once
#include "GeneticAlgorithm.h"

class GeneticAlgorithmFactory
{
public:
    static GeneticAlgorithmFactory& GetInstance();

    template <class Params>
    GeneticAlgorithmPtr<Params> CreateAlgorithm(ProblemType problem,
        Method m, const Params& params, const std::string& inputDataFile);

    /// prevent copying
    GeneticAlgorithmFactory(GeneticAlgorithmFactory const&) = delete;
    void operator=(GeneticAlgorithmFactory const&) = delete;

    /// prevent moving
    GeneticAlgorithmFactory(GeneticAlgorithmFactory const&&) = delete;
    void operator=(GeneticAlgorithmFactory const&&) = delete;

protected:
    GeneticAlgorithmFactory() = default;
};

template<class Params>
inline GeneticAlgorithmPtr<Params> GeneticAlgorithmFactory::CreateAlgorithm(ProblemType problem,
    Method m, const Params& p, const std::string& inputDataFile)
{
    return nullptr;
}