#include "stdafx.h"
#include "FloorPlanningSolver.h"
#include <algorithm>

void FloorPlanningSolver::Init(MatroidPtr matroid, FloorPlanningMatroidParams & params)
{
    m_matroid = matroid;
    m_params = params;
}

void FloorPlanningSolver::Solve()
{

}

FloorPlanningMatroidParams::ResultType FloorPlanningSolver::GetResults()
{
    return FloorPlanningMatroidParams::ResultType();
}

void FloorPlanningSolver::LinearOrder()
{
    auto& modules = m_matroid->GetIndependentSubsets();

    FloorPlanningMatroidParams::SubSetsSet order;
    order.reserve(modules.size());

    std::vector<long> gains (modules.size(), 0);

    // TODO: Consider other approaches for seed selection (random..)
    auto seed = modules.back();

    order.push_back(seed);
    modules.pop_back();

    while (!modules.empty())
    {
        for (auto i = 0; i != modules.size(); ++i)
        {
            gains[i] = ComputeGain(modules[i]);
        }
    }

    auto maxModule = *(std::max_element(gains.begin(), gains.end()));

}

long FloorPlanningSolver::ComputeGain(FloorPlanningMatroidParams::Module & m)
{
    return 0;
}
