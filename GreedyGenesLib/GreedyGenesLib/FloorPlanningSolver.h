#pragma once

#include "GreedyGenesSDK.h"
#include "GreedyStrategy.h"
#include <unordered_map>

class FloorPlanningSolver : public GreedyStrategy<FloorPlanningMatroidParams>
{
public:
    void Init(MatroidPtr matroid, FloorPlanningMatroidParams& params) override;

    void Solve() override;

    FloorPlanningMatroidParams::ResultType GetResults() override;

private:
    // Helpers
    void LinearOrder();
    long ComputeGain(FloorPlanningMatroidParams::ElementType& m);
    void RemoveMaxModule(FloorPlanningMatroidParams::CollectionType modules, SizeType pos);

private:
    MatroidPtr m_matroid;
    FloorPlanningMatroidParams m_params;

    FloorPlanningMatroidParams::CollectionType m_order;
    std::unordered_map<uint64_t, std::tuple<long, long, long>> m_network;
};