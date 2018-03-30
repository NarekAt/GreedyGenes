#include "stdafx.h"
#include "CellPlacementMatroid.h"

bool CellPlacementMatroid::IsIndependentSubset(CellPlacementMatroidParams::CollectionType & elems) const
{
    return false;
}

CellPlacementMatroidParams::CollectionType & CellPlacementMatroid::GetGroundElements() const
{
    return m_groundSet;
}

CellPlacementMatroidParams::SubSetsSet & CellPlacementMatroid::GetIndependentSubsets() const
{
    return m_connMatrix;
}
