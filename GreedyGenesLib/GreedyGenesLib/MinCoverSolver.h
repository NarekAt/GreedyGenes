#pragma once

#include "GreedySDK.h"
#include "GreedyStrategy.h"

class MinCoverSolver : public GreedyStrategy<ClusterMatroidParams>
{
public:
    MinCoverSolver(const std::string& fileName, ClusterMatroidParams& params);

    MatroidPtr GetProblemMatroid() override;

    ClusterMatroidParams& GetParams() override;

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
