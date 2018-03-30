#pragma once

#include "Matroid.h"

class CellPlacementMatroid : public IMatroid<CellPlacementMatroidParams>
{
public:
    bool IsIndependentSubset(CellPlacementMatroidParams::CollectionType& elems) const override;

    CellPlacementMatroidParams::CollectionType& GetGroundElements() const override;

    CellPlacementMatroidParams::SubSetsSet& GetIndependentSubsets() const override;

private:
    mutable CellPlacementMatroidParams::CollectionType m_groundSet;
    mutable CellPlacementMatroidParams::SubSetsSet m_connMatrix;
};
