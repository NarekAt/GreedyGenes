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
    using SubSetsSet = std::vector<CollectionType>;
    using ResultType = std::pair<SubSetsSet, SizeType>;

    // data
    uint8_t  alpha;
    uint32_t k;
};


struct FloorPlanningMatroidParams
{
    // types
    using ElementType = long;

    struct Module
    {
        long height;
        long weight;
        std::vector<ElementType> net;
    };

    using CollectionType = std::vector<ElementType>;
    using SubSetsSet = std::vector<Module>;
    using ResultType = std::vector<long>;
};
