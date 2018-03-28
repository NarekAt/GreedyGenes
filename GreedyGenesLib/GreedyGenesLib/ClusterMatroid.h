#pragma once

#include "Matroid.h"

class ClusterMatroid : public IMatroid<ClusterMatroidParams>
{
public:
    bool IsIndependentSubset(ClusterMatroidParams::CollectionType& elems) const override;

    ClusterMatroidParams::CollectionType& GetGroundElements() const override;

    ClusterMatroidParams::SubSetsSet& GetIndependentSubsets() const override;

private:
    mutable ClusterMatroidParams::CollectionType m_groundSet;
    mutable ClusterMatroidParams::SubSetsSet m_clusters;
};