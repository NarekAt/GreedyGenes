#pragma once
#include <vector>
#include <stdint.h>
#include <limits>

class Chromosome
{
public:
    using Genes = std::vector<uint64_t>;

    Chromosome(const Genes& genes)
        : m_fitness(std::numeric_limits<long>::max())
        , m_genes(genes)
    {}

    Genes& Representation() const
    {
        return m_genes;
    }

    long GetFitness() const
    {
        return m_fitness;
    }

    void SetFitness(long fitness)
    {
        m_fitness = fitness;
    }

protected:
    long m_fitness;

    mutable Genes m_genes;
};
