#include "MaxClusterSolver.h"
#include "ClusterMatroid.h"

MaxClusterSolver::MaxClusterSolver(const std::string& fileName, ClusterMatroidParams& params)
    : m_matroid(std::make_shared<ClusterMatroid>())
    , m_params(params)
{
    m_matroid->ReadInputDataFromFile(fileName);
}

MaxClusterSolver::MatroidPtr MaxClusterSolver::GetProblemMatroid()
{
    return m_matroid;
}

ClusterMatroidParams& MaxClusterSolver::GetParams()
{
    return m_params;
}

void MaxClusterSolver::Solve()
{
}

ClusterMatroidParams::ResultType MaxClusterSolver::GetResults()
{
    return ClusterMatroidParams::ResultType();
}

std::string MaxClusterSolver::StoreResults()
{
    std::string fileName = "max_cluster.out";
    return fileName;
}
