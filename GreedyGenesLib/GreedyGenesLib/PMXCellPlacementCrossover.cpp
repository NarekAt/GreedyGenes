#include "stdafx.h"
#include "PMXCellPlacementCrossover.h"

#include <unordered_map>
#include <random>
#include <cassert>

constexpr char emptyGene = 'x';

std::vector<ChromosomePtr>
PMXCellPlacementCrossover::Crossover(ChromosomePtr parent1, ChromosomePtr parent2)
{
    std::vector<ChromosomePtr> crossovers(1);

    auto chromosome1 = parent1->AsString();
    auto chromosome2 = parent2->AsString();
    assert(chromosome1.size() == chromosome2.size());

    const size_t size = chromosome1.size();

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, size - 1);

    const auto cutPoint = dist(rng);

    std::string offSpring(cutPoint, emptyGene);
    offSpring += chromosome2.substr(cutPoint + 1);

    std::unordered_map<char, size_t> mapping;
    for (size_t i = cutPoint + 1; i != size; ++i)
    {
        mapping.insert({ offSpring[i], i });
    }

    for (size_t i = 0; i <= cutPoint; ++i)
    {
        if (mapping.find(chromosome1[i]) == mapping.end())
        {
            offSpring[i] = chromosome1[i];
        }
        else
        {
            size_t pos = mapping[chromosome1[i]];
            while (true)
            {
                const auto it = mapping.find(chromosome1[pos]);
                if (it == mapping.end())
                {
                    offSpring[i] = chromosome1[pos];
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
