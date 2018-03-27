#pragma once


class IAlgorithm
{
public:
    virtual void Solve() = 0;

    virtual ~IAlgorithm() = default;
};
