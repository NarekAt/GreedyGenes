#pragma once

#include "GreedySDK.h"
#include "GreedyStrategy.h"

class MaxClusterSolver : public GreedyStrategy<ClusterMatroidParams>
{
public:
    MaxClusterSolver(const std::string& fileName, ClusterMatroidParams& params);

    MatroidPtr GetProblemMatroid() override;

    ClusterMatroidParams& GetParams() override;

    void Solve() override;

    ClusterMatroidParams::ResultType GetResults() override;

private:
    MatroidPtr m_matroid;
    ClusterMatroidParams m_params;
};
