#include "FloorPlanningMatroid.h"

void FloorPlanningMatroid::ReadInputDataFromFile(const std::string & filePath)
{
}

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
