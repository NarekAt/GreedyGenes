#pragma once

#include "GreedySDK.h"
#include "GreedyStrategy.h"

class MinCoverSolver : public GreedyStrategy<ClusterMatroidParams>
{
public:
    void Init(MatroidPtr matroid, ClusterMatroidParams& params) override;

    void Solve() override;

    ClusterMatroidParams::ResultType GetResults() override;

private:
    void Prepare();

private:
    MatroidPtr m_matroid;
    ClusterMatroidParams m_params;
    size_t m_maxWeight;
    ClusterMatroidParams::SubSetsSet m_clusterCover;
};
