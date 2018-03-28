#pragma once

#include "Matroid.h"

class FloorPlanningMatroid : public IMatroid<FloorPlanningMatroidParams>
{
public:
    bool IsIndependentSubset(FloorPlanningMatroidParams::CollectionType& elems) const override;

    FloorPlanningMatroidParams::CollectionType& GetGroundElements() const override;

    FloorPlanningMatroidParams::SubSetsSet& GetIndependentSubsets() const override;

private:
    mutable FloorPlanningMatroidParams::CollectionType m_groundSet;
    mutable FloorPlanningMatroidParams::SubSetsSet m_modules;
};
