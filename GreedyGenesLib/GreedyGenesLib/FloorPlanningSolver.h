#pragma once

#include "GreedySDK.h"
#include "GreedyStrategy.h"
#include <unordered_map>

class FloorPlanningSolver : public GreedyStrategy<FloorPlanningMatroidParams>
{
public:
    FloorPlanningSolver(const std::string& inputFile, FloorPlanningMatroidParams& params);

    MatroidPtr GetProblemMatroid() override;

    FloorPlanningMatroidParams& GetParams() override;

    void Solve() override;

    FloorPlanningMatroidParams::ResultType GetResults() override;

private:
    // Helpers
    void LinearOrder();
    long ComputeGain(FloorPlanningMatroidParams::ElementType& m);
    void RemoveMaxModule(FloorPlanningMatroidParams::CollectionType modules, size_t pos);

private:
    MatroidPtr m_matroid;
    FloorPlanningMatroidParams m_params;

    FloorPlanningMatroidParams::CollectionType m_order;
    std::unordered_map<uint64_t, std::tuple<long, long, long>> m_network;
};
