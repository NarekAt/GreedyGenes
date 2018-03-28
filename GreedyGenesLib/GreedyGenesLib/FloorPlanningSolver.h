#pragma once

#include "GreedyGenesSDK.h"
#include "GreedyStrategy.h"

class FloorPlanningSolver : public GreedyStrategy<FloorPlanningMatroidParams>
{
public:
    void Init(MatroidPtr matroid, FloorPlanningMatroidParams& params) override;

    void Solve() override;

    FloorPlanningMatroidParams::ResultType GetResults() override;

private:
    void LinearOrder();
    long ComputeGain(FloorPlanningMatroidParams::Module& m);

private:
    MatroidPtr m_matroid;
    FloorPlanningMatroidParams m_params;
    SizeType m_maxWeight;
};
