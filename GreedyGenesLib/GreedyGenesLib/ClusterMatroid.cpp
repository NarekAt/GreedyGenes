#include "stdafx.h"
#include "ClusterMatroid.h"

bool ClusterMatroid::IsIndependentSubset(ClusterMatroidParams::CollectionType& elems) const
{
    return false;
}

ClusterMatroidParams::CollectionType& ClusterMatroid::GetGroundElements() const
{
    return m_groundSet;
}

ClusterMatroid::SubSetsSet& ClusterMatroid::GetIndependentSubsets() const
{
    return m_clusters;
}
