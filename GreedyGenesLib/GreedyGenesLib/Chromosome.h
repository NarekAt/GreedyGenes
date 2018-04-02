#pragma once
#include <string>

class Chromosome
{
public:
    Chromosome(const std::string& genes)
        : m_fitness(std::numeric_limits<long>::max())
        , m_genes(genes)
    {}

    std::string& AsString() const
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

    mutable std::string m_genes;
};
