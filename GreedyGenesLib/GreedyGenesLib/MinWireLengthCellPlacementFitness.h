#pragma once
#include "FitnessEvaluationStrategy.h"
#include "GreedySDK.h"

class MinWireLengthCellPlacementFitness : public FitnessEvaluationStrategy<CellPlacementMatroidParams>
{
public:
    void Evaluate(Generation& generation) override;

private:
    using Grid = std::vector<std::vector<size_t>>;

    long GetManhattanDistance(ChromosomePtr ch, size_t i, size_t j);
};
