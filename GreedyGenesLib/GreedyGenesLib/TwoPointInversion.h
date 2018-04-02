#pragma once

#include "InversionStrategy.h"

class TwoPointInversion : public InversionStrategy
{
public:
    TwoPointInversion(uint16_t inversionRate)
        : m_rate(inversionRate)
    {}

    void Inverse(Generation& gen) override;

private:
    uint16_t m_rate;
};
