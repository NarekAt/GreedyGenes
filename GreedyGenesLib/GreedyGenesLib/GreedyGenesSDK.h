#pragma once

#include "Matroid.h"
#include <memory>
#include <vector>
#include <set>

using SizeType = long;


struct ClusterMatroidParams
{
    // types
    struct ElementType
    {
        std::pair<long, long> elem;

        long weight;

        bool operator<(const ElementType& rhs) const
        {
            return elem < rhs.elem;
        }
    };

    using CollectionType = std::set<ElementType>;
    using ClusterCoverType = std::vector<CollectionType>;
    using ResultType = std::pair<ClusterCoverType, SizeType>;

    // data
    uint8_t  alpha;
    uint32_t k;
};
