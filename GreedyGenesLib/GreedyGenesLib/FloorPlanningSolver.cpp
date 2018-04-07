#include "FloorPlanningSolver.h"
#include "FloorPlanningMatroid.h"
#include <algorithm>

FloorPlanningSolver::FloorPlanningSolver(const std::string& fileName, FloorPlanningMatroidParams & params)
    : m_matroid(std::make_shared<FloorPlanningMatroid>())
    , m_params(params)
{
    m_matroid->ReadInputDataFromFile(fileName);
}

FloorPlanningSolver::MatroidPtr FloorPlanningSolver::GetProblemMatroid()
{
    return m_matroid;
}

FloorPlanningMatroidParams & FloorPlanningSolver::GetParams()
{
    return m_params;
}

void FloorPlanningSolver::Solve()
{
    LinearOrder();

    auto it = m_order.begin();

    while (!m_order.empty())
    {
        m_order.erase(it);
        ++it;
        // select a location for mod that will result in
        // minimum increase in cost function
    }
}

FloorPlanningMatroidParams::ResultType FloorPlanningSolver::GetResults()
{
    return FloorPlanningMatroidParams::ResultType();
}

void FloorPlanningSolver::LinearOrder()
{
    auto& modules = m_matroid->GetGroundElements();
    auto& nets = m_matroid->GetIndependentSubsets();

    m_order.reserve(modules.size());

    std::vector<long> gains (modules.size(), 0);

    // TODO: Consider other approaches for seed selection (random..)
    auto seed = modules.back();

    m_order.push_back(seed);
    modules.pop_back();

    while (!modules.empty())
    {
        for (size_t i = 0; i != modules.size(); ++i)
        {
            gains[i] = ComputeGain(modules[i]);
        }

        FloorPlanningMatroidParams::CollectionType ties;
        long max = std::numeric_limits<long>::min();
        size_t maxPos = -1;

        for (size_t i = 0; i != gains.size(); ++i)
        {
            if (gains[i] >= max)
            {
                ties.push_back(modules[i]);
                max = gains[i];
                maxPos = i;
            }
        }

        if (ties.size() == 1)
        {
            m_order.push_back(ties.back());
        }
        else
        {
            // select the module that terminates the largest number of nets

            // select the module that has the largest number of continuing nets

            // select the module with the least number of connections
        }
        RemoveMaxModule(modules, maxPos);
    }
}

long FloorPlanningSolver::ComputeGain(FloorPlanningMatroidParams::ElementType& m)
{
    const auto& nets = m_matroid->GetIndependentSubsets();

    long numOfNetsTerminatedByM = 0;
    long numOfNetsStartedByM = 0;
    long numOfNetsContinuingByM = 0;

    for (const auto& net : nets)
    {
        if (net.empty())
            continue;

        auto it = std::find_if(net.begin(), net.end(),
            [&](FloorPlanningMatroidParams::ElementType e)
            {
                return e.id == m.id;
            });

        if (it == net.end())
            continue;

        if ( it == net.begin())
        {
            ++numOfNetsStartedByM;
        }
        else if (it == net.end())
        {
            ++numOfNetsTerminatedByM;
        }
        else
        {
            ++numOfNetsContinuingByM;
        }
    }

    m_network[m.id] = std::make_tuple(numOfNetsTerminatedByM, numOfNetsStartedByM, numOfNetsContinuingByM);

    return (numOfNetsTerminatedByM - numOfNetsStartedByM);
}

void FloorPlanningSolver::RemoveMaxModule(FloorPlanningMatroidParams::CollectionType modules, size_t pos)
{
    modules.erase(modules.begin() + pos);
}
