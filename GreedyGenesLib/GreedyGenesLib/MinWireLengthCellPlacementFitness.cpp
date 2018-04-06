#include "MinWireLengthCellPlacementFitness.h"
#include <cmath>

void
MinWireLengthCellPlacementFitness::Evaluate(Generation& generation)
{
    auto& connMatrix = m_problem->GetIndependentSubsets();

    for (auto chromosome : generation)
    {
        long weightedWireLength = 0;
        // Iterate over all the nets
        for (size_t i = 0; i != connMatrix.size(); ++i)
        {
            for (size_t j = 0; j != connMatrix[j].size(); ++j)
            {
                if (connMatrix[i][j] == std::numeric_limits<size_t>::max())
                    continue;

                weightedWireLength += GetManhattanDistance(chromosome, i, j) * connMatrix[i][j];
            }
        }
        chromosome->SetFitness(weightedWireLength);
    }
}

long
MinWireLengthCellPlacementFitness::GetManhattanDistance(ChromosomePtr ch, size_t i, size_t j)
{
    auto& genes = ch->Representation();

    size_t numOfRows = static_cast<size_t>(sqrt(genes.size()));

    std::pair<size_t, size_t> c1, c2;

    for (size_t k = 0; k != genes.size(); ++k)
    {
        // TODO: refactor code
        auto chromId = genes[k];
        if (chromId == i)
        {
            c1.first = k / numOfRows;
            c1.second = k % numOfRows;
        }
        else if (chromId == j)
        {
            c2.first = k / numOfRows;
            c2.second = k % numOfRows;
        }
    }

    return abs(long(c1.first - c2.first)) + abs(long(c1.second - c2.second));
}
