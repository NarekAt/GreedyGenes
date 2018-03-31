#pragma once

#include "CrossoverStrategy.h"

class PMXCellPlacementCrossover : public CrossoverStrategy
{
public:
    ChromosomePtr Crossover(ChromosomePtr parent1, ChromosomePtr parent2) override;
};
