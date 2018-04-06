#include "FloorPlanningMatroid.h"

bool FloorPlanningMatroid::IsIndependentSubset(FloorPlanningMatroidParams::CollectionType & elems) const
{
    return false;
}

FloorPlanningMatroidParams::CollectionType& FloorPlanningMatroid::GetGroundElements() const
{
    return m_groundSet;
}

FloorPlanningMatroidParams::SubSetsSet& FloorPlanningMatroid::GetIndependentSubsets() const
{
    return m_modules;
}
