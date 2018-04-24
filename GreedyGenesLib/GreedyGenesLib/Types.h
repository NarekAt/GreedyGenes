#pragma once

enum class FloorPlanningCoastCriteria
{
    MIN_AREA,
    MIN_WIRE,
    MAX_ROUTE,
    MIN_DELAY
};

enum class CellPlacementCriteria
{
    MIN_WIRE,
    MIN_MAX_CUT
};

enum class ProblemType
{
    VLSI_CELL_PLACEMENT,
    VLSI_FLOOR_PLANNING,
    ALPHA_CLUSTER_COVER,
    K_CLUSTER_COVER,
    TRAVELING_SALESMAN
};

enum class Method
{
    GREEDY,
    GENETIC,
    GREEDY_GENETIC
};
