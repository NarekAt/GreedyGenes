#pragma once

#include "MutationStrategy.h"

class PairwiseInterchangeMutatation : public MutatationStrategy
{
public:
    PairwiseInterchangeMutatation(uint16_t mutationRate)
        : m_rate(mutationRate)
    {}

    void Mutate(Generation& gen) override;

private:
    uint16_t m_rate;
};
