#ifndef OPTIMIZATIONSALGORITHMFACTORY_H
#define OPTIMIZATIONSALGORITHMFACTORY_H

#include "Algorithm.h"
#include "Types.h"
#include <map>

class OptimizationsAlgorithmFactory
{
public:
    static OptimizationsAlgorithmFactory& GetInstance();

    AlgorithmPtr CreateAlgorithm(ProblemType problemType,
                                 Method method,
                                 const std::string& inputFilePath,
                                 const std::map<std::string, std::string>& additionalOptions);


    /// prevent copying
    OptimizationsAlgorithmFactory(OptimizationsAlgorithmFactory const&) = delete;
    void operator=(OptimizationsAlgorithmFactory const&) = delete;

    /// prevent moving
    OptimizationsAlgorithmFactory(OptimizationsAlgorithmFactory const&&) = delete;
    void operator=(OptimizationsAlgorithmFactory const&&) = delete;

protected:
    OptimizationsAlgorithmFactory() = default;

private:
    AlgorithmPtr InstantiateGreedyAlgorithm(ProblemType problemType,
        const std::string& inputFilePath,
        const std::map<std::string, std::string>& additionalOptions);

    AlgorithmPtr InstantiateGeneticAlgorithm(ProblemType problemType,
        const std::string& inputFilePath,
        const std::map<std::string, std::string>& additionalOptions);

    AlgorithmPtr InstantiateGreedyGeneticAlgorithm(ProblemType problemType,
        const std::string& inputFilePath,
        const std::map<std::string, std::string>& additionalOptions);
};

#endif // OPTIMIZATIONSALGORITHMFACTORY_H
