#include "PMXCellPlacementCrossover.h"

#include <unordered_map>
#include <random>
#include <cassert>

constexpr long emptyGene = -1;

std::vector<ChromosomePtr>
PMXCellPlacementCrossover::Crossover(ChromosomePtr parent1, ChromosomePtr parent2)
{
    std::vector<ChromosomePtr> crossovers(1);

    auto genes1 = parent1->Representation();
    auto genes2 = parent2->Representation();
    assert(genes1.size() == genes2.size());

    const size_t size = genes1.size();

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, size - 1);

    const auto cutPoint = dist(rng);

    Chromosome::Genes offSpring(cutPoint, emptyGene);
    offSpring.insert(offSpring.end(), genes2.begin() + cutPoint + 1, genes2.end());

    std::unordered_map<uint64_t, size_t> mapping;
    for (size_t i = cutPoint + 1; i != size; ++i)
    {
        mapping.insert({ offSpring[i], i });
    }

    for (size_t i = 0; i <= cutPoint; ++i)
    {
        if (mapping.find(genes1[i]) == mapping.end())
        {
            offSpring[i] = genes1[i];
        }
        else
        {
            size_t pos = mapping[genes1[i]];
            while (true)
            {
                const auto it = mapping.find(genes1[pos]);
                if (it == mapping.end())
                {
                    offSpring[i] = genes1[pos];
                    break;
                }
                else
                {
                    pos = it->second;
                }
            }
        }
    }

    crossovers[0] = std::make_shared<Chromosome>(offSpring);

    return crossovers;
}
