#pragma once
#include "FitnessEvaluationStrategy.h"
#include "GreedySDK.h"

class MinWireLengthCellPlacementFitness : public FitnessEvaluationStrategy
{
public:
    MinWireLengthCellPlacementFitness(IMatroidPtr<CellPlacementMatroidParams> matroid)
        : m_problem(matroid)
    {}

    void Evaluate(Generation& generation) override;

private:
    using Grid = std::vector<std::vector<size_t>>;

    long GetManhattanDistance(ChromosomePtr ch, size_t i, size_t j);

private:
    IMatroidPtr<CellPlacementMatroidParams> m_problem;
};
