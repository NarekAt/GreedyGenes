#pragma once

#include "InversionStrategy.h"

class TwoPointInversion : public InversionStrategy
{
public:
    TwoPointInversion(double inversionRate)
        : m_rate(inversionRate)
    {}

    void Inverse(Generation& gen) override;

private:
    double m_rate;
};
