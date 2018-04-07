#include "MinCoverSolver.h"
#include "ClusterMatroid.h"
#include <iterator>
#include <algorithm>

MinCoverSolver::MinCoverSolver(const std::string& fileName, ClusterMatroidParams& params)
    : m_matroid(std::make_shared<ClusterMatroid>())
    , m_params(params)
{
    m_matroid->ReadInputDataFromFile(fileName);
}

MinCoverSolver::MatroidPtr MinCoverSolver::GetProblemMatroid()
{
    return m_matroid;
}

ClusterMatroidParams& MinCoverSolver::GetParams()
{
    return m_params;
}

void MinCoverSolver::Solve()
{
    Prepare();

    ClusterMatroidParams::CollectionType E1;
    int k = 0;

    auto groundSet = m_matroid->GetGroundElements();
    auto clusters = m_matroid->GetIndependentSubsets();
    std::vector<size_t> clusterWeights(clusters.size(), 0);

    while (E1.size() < m_params.alpha * groundSet.size())
    {
        // k-th greedy peeling
        ++k;

        // solve
        auto maxCluster = *(std::max_element(clusters.begin(), clusters.end(),
            [&](auto& v1, auto& v2)
        {
            return v1.size() < v2.size();
        }));

        // peel-off
        for (size_t i = 0; i != clusters.size() && clusters[i].size() != 0; ++i)
        {
            auto& cluster = clusters[i];
            ClusterMatroidParams::CollectionType diff;

            std::set_difference(cluster.begin(), cluster.end(), maxCluster.begin(), maxCluster.end(),
                std::inserter(diff, diff.begin()));

            cluster = std::move(diff);

            ClusterMatroidParams::CollectionType intersection;
            std::set_intersection(cluster.begin(), cluster.end(), maxCluster.begin(), maxCluster.end(),
                std::inserter(intersection, intersection.begin()));

            clusterWeights[i] += intersection.size() / maxCluster.size();
        }

        ClusterMatroidParams::CollectionType unionSet;
        std::set_union(E1.begin(), E1.end(), maxCluster.begin(), maxCluster.end(),
            std::inserter(unionSet, unionSet.begin()));

        E1 = std::move(unionSet);

        // Augment
        m_clusterCover.push_back(maxCluster);
    }

    m_maxWeight = *(std::max_element(clusterWeights.begin(), clusterWeights.end()));
}

ClusterMatroidParams::ResultType MinCoverSolver::GetResults()
{
    return ClusterMatroidParams::ResultType({ m_clusterCover, m_maxWeight });
}

void MinCoverSolver::Prepare()
{
    m_clusterCover.clear();
}
