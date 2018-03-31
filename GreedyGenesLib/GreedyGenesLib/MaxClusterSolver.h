#pragma once

#include "GreedySDK.h"
#include "GreedyStrategy.h"

class MaxClusterSolver : public GreedyStrategy<ClusterMatroidParams>
{
public:
    void Init(MatroidPtr matroid, ClusterMatroidParams& params) override;

    void Solve() override;

    ClusterMatroidParams::ResultType GetResults() override;

private:
    MatroidPtr m_matroid;
    ClusterMatroidParams m_params;
};
