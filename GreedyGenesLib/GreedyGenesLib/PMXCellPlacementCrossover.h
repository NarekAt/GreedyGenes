#pragma once

#include "CrossoverStrategy.h"
#include <vector>

class PMXCellPlacementCrossover : public CrossoverStrategy
{
public:
    std::vector<ChromosomePtr> Crossover(ChromosomePtr parent1, ChromosomePtr parent2) override;
};
