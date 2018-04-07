#include "CellPlacementMatroid.h"

void CellPlacementMatroid::ReadInputDataFromFile(const std::string& filePath)
{

}

bool CellPlacementMatroid::IsIndependentSubset(CellPlacementMatroidParams::CollectionType & elems) const
{
    return false;
}

CellPlacementMatroidParams::CollectionType& CellPlacementMatroid::GetGroundElements() const
{
    return m_groundSet;
}

CellPlacementMatroidParams::SubSetsSet& CellPlacementMatroid::GetIndependentSubsets() const
{
    return m_connMatrix;
}
