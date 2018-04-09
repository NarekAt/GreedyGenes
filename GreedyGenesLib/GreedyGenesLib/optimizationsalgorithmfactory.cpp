#include "optimizationsalgorithmfactory.h"
#include "GreedyAlgorithm.h"

// greedy
#include "CellPlacementMaxConSolver.h"
#include "FloorPlanningSolver.h"
#include "MinCoverSolver.h"
#include "MaxClusterSolver.h"

// genetic
#include "MinWireLengthCellPlacementFitness.h"
#include "PairwiseInterchangeMutation.h"
#include "PMXCellPlacementCrossover.h"
#include "TwoPointInversion.h"
#include "IncrementalGeneticAlgorithm.h"
#include "GreedyPopulationGeneticAlgorithm.h"

OptimizationsAlgorithmFactory& OptimizationsAlgorithmFactory::GetInstance()
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
    const std::string& inputFilePath, const std::map<std::string, std::string>& additionalOptions)
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
        FloorPlanningMatroidParams params;
        params.coast = FloorPlanningCoastCriteria::MIN_WIRE;

        auto solver = std::make_shared<FloorPlanningSolver>(inputFilePath, params);
        return std::make_shared<GreedyAlgorithm<FloorPlanningMatroidParams>>(solver);
    }
    case ProblemType::ALPHA_CLUSTER_COVER:
    {

    }
    case ProblemType::K_CLUSTER_COVER:
    {

    }
    default:
        // TODO: logger log
        break;

    };
    return nullptr;
}

AlgorithmPtr OptimizationsAlgorithmFactory::InstantiateGeneticAlgorithm(ProblemType problemType, const std::string &inputFilePath, const std::map<std::string, std::string> &additionalOptions)
{
    switch (problemType)
    {
    case ProblemType::VLSI_CELL_PLACEMENT:
    {
        CellPlacementMatroidParams params;
        params.coast = CellPlacementCriteria::MIN_WIRE;

        auto solver = std::make_shared<CellPlacementMaxConSolver>(inputFilePath, params);
        auto fitness = std::make_shared<MinWireLengthCellPlacementFitness>(solver->GetProblemMatroid());
        //auto mutation = std::make_shared<PairwiseInterchangeMutatation>();

    }
    case ProblemType::VLSI_FLOOR_PLANNING:
    {

    }
    case ProblemType::ALPHA_CLUSTER_COVER:
    {
        // TODO: Log about this
        return nullptr;
    }
    case ProblemType::K_CLUSTER_COVER:
    {
        // TODO: Log about this
        return nullptr;
    }
    default:
        break;
    }
    return nullptr;
}

AlgorithmPtr OptimizationsAlgorithmFactory::InstantiateGreedyGeneticAlgorithm(ProblemType problemType, const std::string & inputFilePath, const std::map<std::string, std::string>& additionalOptions)
{
    return AlgorithmPtr();
}
