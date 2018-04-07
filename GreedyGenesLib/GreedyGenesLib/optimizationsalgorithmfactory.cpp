#include "optimizationsalgorithmfactory.h"
#include "GreedyAlgorithm.h"

#include "CellPlacementMaxConSolver.h"

OptimizationsAlgorithmFactory &OptimizationsAlgorithmFactory::GetInstance()
{
    static OptimizationsAlgorithmFactory instance;
    return instance;
}

AlgorithmPtr OptimizationsAlgorithmFactory::CreateAlgorithm(ProblemType problemType,
    Method method,
    const std::string & inputFilePath,
    const std::map<std::string, std::string>& additionalOptions)
{
    switch (method)
    {
    case Method::GREEDY:
        return InstantiateGreedyAlgorithm(problemType, inputFilePath, additionalOptions);
    case Method::GENETIC:
    case Method::GREEDY_GENETIC:
        return InstantiateGeneticAlgorithm(problemType, inputFilePath, additionalOptions);
    default:
        return nullptr;
    }

    return nullptr;
}

AlgorithmPtr OptimizationsAlgorithmFactory::InstantiateGreedyAlgorithm(ProblemType problemType,
    const std::string &inputFilePath, const std::map<std::string, std::string> &additionalOptions)
{
    switch (problemType)
    {
    case ProblemType::VLSI_CELL_PLACEMENT:
    {
        CellPlacementMatroidParams params;
        params.coast = CellPlacementCriteria::MIN_WIRE;

        auto solver = std::make_shared<CellPlacementMaxConSolver>(inputFilePath, params);
        return std::make_shared<GreedyAlgorithm<CellPlacementMatroidParams>>(solver);
    }
    case ProblemType::VLSI_FLOOR_PLANNING:
    {

    }
    case ProblemType::ALPHA_CLUSTER_COVER:
    {

    }
    case ProblemType::K_CLUSTER_COVER:
    {

    }
    default:
        break;

    };
    return nullptr;
}

AlgorithmPtr OptimizationsAlgorithmFactory::InstantiateGeneticAlgorithm(ProblemType problemType, const std::string &inputFilePath, const std::map<std::string, std::string> &additionalOptions)
{
    return nullptr;
}
