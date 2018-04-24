#pragma once

#include "Matroid.h"
#include "Types.h"

#include <memory>
#include <vector>
#include <set>

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
    using ResultType = std::pair<SubSetsSet, size_t>;

    // data
    uint8_t  alpha;
    uint32_t k;
};

struct Cell
{
    size_t id;

    long height;
    long width;
};


struct FloorPlanningMatroidParams
{
    // types

    using ElementType = Cell;
    using CollectionType = std::vector<ElementType>;
    using SubSetsSet = std::vector<CollectionType>;
    using ResultType = std::vector<long>;

    FloorPlanningCoastCriteria coast;
};

struct CellPlacementMatroidParams
{
    using ElementType = Cell;
    using CollectionType = std::vector<ElementType>;

    // Connectivity matrix
    using SubSetsSet = std::vector<std::vector<size_t>>;
    using ResultType = std::vector<uint64_t>;

    CellPlacementCriteria coast;
};


#include "tsp.h"

struct TSPMatroidParams
{
    // vertices
    using CollectionType = std::vector<int>;
    using SubSetsSet = Graph;
    using ResultType = std::vector<uint64_t>;
};
