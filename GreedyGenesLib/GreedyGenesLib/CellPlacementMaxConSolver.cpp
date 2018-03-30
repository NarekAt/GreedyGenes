#include "stdafx.h"
#include "CellPlacementMaxConSolver.h"
#include <exception>

namespace
{
    constexpr auto INVALID_SLOT = std::numeric_limits<size_t>::max();
}

void CellPlacementMaxConSolver::Init(MatroidPtr matroid, CellPlacementMatroidParams& params)
{
    m_matroid = matroid;
    m_params = params;
}

void CellPlacementMaxConSolver::Solve()
{
    auto& cells = m_matroid->GetGroundElements();

    // Initialize slots with empty values
    m_result.resize(cells.size(), INVALID_SLOT);

    auto seedCell = SeedCell();

    // Place the Seed cell in the center
    m_result[seedCell.id] = cells.size() / 2;

    for (auto& cell : cells)
    {
        auto sc = SelectCell(m_result);
        auto ss = SelectSlot(sc);

        m_result[sc.id] = ss;
    }
}

CellPlacementMatroidParams::ResultType CellPlacementMaxConSolver::GetResults()
{
    return m_result;
}

Cell CellPlacementMaxConSolver::SeedCell()
{
    // pickup cell with max connectivity
    Cell maxCell = {};
    const auto& connMatrix = m_matroid->GetIndependentSubsets();

    auto maxCon = std::numeric_limits<size_t>::min();

    for (size_t i = 0; i != connMatrix.size(); ++i)
    {
        size_t connections = 0;

        for (size_t j = 0; j != connMatrix[i].size(); ++j)
        {
            connections += connMatrix[i][j];
        }

        if (connections > maxCon)
        {
            maxCon = connections;
            maxCell.id = i;
        }
    }
    return maxCell;
}

Cell CellPlacementMaxConSolver::SelectCell(const CellPlacementMatroidParams::ResultType& layout)
{
    Cell maxCell = {};

    const auto& connMatrix = m_matroid->GetIndependentSubsets();

    auto maxCon = std::numeric_limits<size_t>::min();

    for (size_t i = 0; i != connMatrix.size(); ++i)
    {
        size_t connections = 0;

        for (size_t j = 0; j != connMatrix[i].size(); ++j)
        {
            if (layout[j] == INVALID_SLOT)
                continue;

            connections += connMatrix[i][j];
        }
        
        if (connections > maxCon)
        {
            maxCon = connections;
            maxCell.id = i;
        }
    }
    return maxCell;
}

size_t CellPlacementMaxConSolver::SelectSlot(Cell& cell)
{
    if (m_params.coast == CellPlacementCriteria::MIN_WIRE)
    {
        // To minimize the increase in wirelength,
        // module must be placed as close to
        // already placed modules as possible

        const auto size = m_result.size();
        const auto mid = size / 2;

        for (size_t i = mid, j = mid; i >= 0, j < size; --i, ++j)
        {
            if (m_result[i] == INVALID_SLOT)
                return i;

            if (m_result[j] == INVALID_SLOT)
                return j;
        }
    }
    else
    {
        throw std::runtime_error("Not Implemented");
    }

    return INVALID_SLOT;
}
