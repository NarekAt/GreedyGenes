#pragma once

#include "Matroid.h"

class ClusterMatroid : public IMatroid<ClusterMatroidParams>
{
public:
    bool IsIndependentSubset(ClusterMatroidParams::CollectionType& elems) const override;

    ClusterMatroidParams::CollectionType& GetGroundElements() const override;

    SubSetsSet& GetIndependentSubsets() const override;

private:
    mutable ClusterMatroidParams::CollectionType m_groundSet;
    mutable SubSetsSet m_clusters;
};