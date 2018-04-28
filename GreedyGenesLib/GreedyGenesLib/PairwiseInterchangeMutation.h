#pragma once

#include "MutationStrategy.h"

class PairwiseInterchangeMutatation : public MutatationStrategy
{
public:
    PairwiseInterchangeMutatation(double mutationRate)
        : m_rate(mutationRate)
    {}

    void Mutate(Generation& gen) override;

private:
    double m_rate;
};
