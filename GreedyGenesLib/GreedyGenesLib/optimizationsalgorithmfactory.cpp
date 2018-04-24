#include "optimizationsalgorithmfactory.h"
#include "GreedyAlgorithm.h"

// greedy
#include "CellPlacementMaxConSolver.h"
#include "FloorPlanningSolver.h"
#include "MinCoverSolver.h"
#include "MaxClusterSolver.h"
#include "tspmatroid.h"

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
        ClusterMatroidParams params;
        params.alpha = std::stoi(additionalOptions.at("k number"));
        params.k = std::stoi(additionalOptions.at("alpha number"));

        auto solver = std::make_shared<MinCoverSolver>(inputFilePath, params);
        return std::make_shared<GreedyAlgorithm<ClusterMatroidParams>>(solver);
    }
    case ProblemType::K_CLUSTER_COVER:
    {
        ClusterMatroidParams params;
        params.alpha = std::stoi(additionalOptions.at("k number"));
        params.k = std::stoi(additionalOptions.at("alpha number"));

        auto solver = std::make_shared<MaxClusterSolver>(inputFilePath, params);
        return std::make_shared<GreedyAlgorithm<ClusterMatroidParams>>(solver);
    }
    case ProblemType::TRAVELING_SALESMAN:
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
        auto mutation = std::make_shared<PairwiseInterchangeMutatation>(std::stoi(additionalOptions.at("Mutation Rate")));
        auto inversion = std::make_shared<TwoPointInversion>(std::stoi(additionalOptions.at("Inversion Rate")));
        auto crossover = std::make_shared<PMXCellPlacementCrossover>();
        auto numOfGens = std::stoi(additionalOptions.at("Num of Generation"));

        // TODO: Replace temp number 10
        auto algo = std::make_shared<GreedyPopulationGeneticAlgorithm<CellPlacementMatroidParams>>(crossover, mutation, inversion, fitness, numOfGens, numOfGens / 10);
        auto greedy = std::make_shared<GreedyAlgorithm<CellPlacementMatroidParams>>(solver);
        algo->SetGreedyAlgorithm(*greedy);

        return algo;
    }
    case ProblemType::VLSI_FLOOR_PLANNING:
    {
        // TODO: implement
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
    case ProblemType::TRAVELING_SALESMAN:
    {
        // parameters: the graph, population size, generations and mutation rate
        // optional parameters: show_population
        auto matroid = std::make_shared<TSPMatroid>();
        matroid->ReadInputDataFromFile(inputFilePath);

        Genetic genetic(
                    &matroid->GetIndependentSubsets(),
                    10,
                    std::stoi(additionalOptions.at("Num of Generation")),
                    std::stoi(additionalOptions.at("Mutation Rate")),
                    false);

        genetic.run();

    }
    default:
        break;
    }
    return nullptr;
}

AlgorithmPtr OptimizationsAlgorithmFactory::InstantiateGreedyGeneticAlgorithm(ProblemType problemType, const std::string & inputFilePath, const std::map<std::string, std::string>& additionalOptions)
{
    switch (problemType)
    {
    case ProblemType::VLSI_CELL_PLACEMENT:
    {
        CellPlacementMatroidParams params;
        params.coast = CellPlacementCriteria::MIN_WIRE;

        auto solver = std::make_shared<CellPlacementMaxConSolver>(inputFilePath, params);

        auto fitness = std::make_shared<MinWireLengthCellPlacementFitness>(solver->GetProblemMatroid());
        auto mutation = std::make_shared<PairwiseInterchangeMutatation>(std::stoi(additionalOptions.at("Mutation Rate")));
        auto inversion = std::make_shared<TwoPointInversion>(std::stoi(additionalOptions.at("Inversion Rate")));
        auto crossover = std::make_shared<PMXCellPlacementCrossover>();
        auto numOfGens = std::stoi(additionalOptions.at("Num of Generation"));

        // TODO: Replace temp number 10
        return std::make_shared<IncrementalGeneticAlgorithm<CellPlacementMatroidParams>>(crossover, mutation, inversion, fitness, numOfGens, numOfGens / 10);
    }
    case ProblemType::VLSI_FLOOR_PLANNING:
    {
        // TODO: implement
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
