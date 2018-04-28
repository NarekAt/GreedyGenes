#include "CellPlacementMaxConSolver.h"
#include "CellPlacementMatroid.h"
#include <cassert>
#include <exception>
#include <limits>
#include <fstream>

#include <QtMath>

namespace
{
    constexpr auto INVALID_SLOT = std::numeric_limits<size_t>::max();
}

CellPlacementMaxConSolver::CellPlacementMaxConSolver(const std::string& fileName, CellPlacementMatroidParams & params)
    : m_matroid(std::make_shared<CellPlacementMatroid>())
    , m_params(params)
{
    m_matroid->ReadInputDataFromFile(fileName);
}

CellPlacementMaxConSolver::MatroidPtr CellPlacementMaxConSolver::GetProblemMatroid()
{
    return m_matroid;
}

CellPlacementMatroidParams& CellPlacementMaxConSolver::GetParams()
{
    return m_params;
}

void CellPlacementMaxConSolver::Solve()
{
    auto& cells = m_matroid->GetGroundElements();

    // Initialize slots with empty values
    m_result.resize(cells.size(), INVALID_SLOT);
    m_placed.resize(cells.size(), false);

    auto seedCell = SeedCell();

    // Place the Seed cell in the center
    m_result[cells.size() / 2] = seedCell.id;
    m_placed[seedCell.id] = true;

    for (size_t i = 0; i < cells.size() - 1; ++i)
    {
        auto sc = SelectCell(m_result);
        auto ss = SelectSlot(sc);

        m_result[ss] = sc.id;
        m_placed[sc.id] = true;
    }
}

CellPlacementMatroidParams::ResultType CellPlacementMaxConSolver::GetResults()
{
    return m_result;
}

std::string CellPlacementMaxConSolver::StoreResults()
{
    const std::string fileName = "cell_placement.out";
    assert(!m_result.empty());

    std::ofstream out;
    out.open(fileName);

    out << "CELL PLACEMENT" << "\n" << "\n";

    const size_t n = qSqrt(m_result.size());

    size_t j = m_result.size() - 1;

    for (size_t i = 0; i != n; ++i)
    {
        for (int k = 0; k != n; ++k)
        {
            out << m_result[j--] << " ";
        }
        out << "\n";
    }

    return fileName;
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
    maxCell.id = INVALID_SLOT;

    const auto& connMatrix = m_matroid->GetIndependentSubsets();

    auto maxCon = std::numeric_limits<size_t>::min();

    for (size_t i = 0; i != connMatrix.size(); ++i)
    {
        size_t connections = 0;

        if (m_placed[i])
        {
            continue;
        }

        for (size_t j = 0; j != connMatrix[i].size(); ++j)
        {
            if (!m_placed[j])
                continue;

            connections += connMatrix[i][j];
        }
        
        if (connections > maxCon)
        {
            maxCon = connections;
            maxCell.id = i;
        }
    }
    if (maxCell.id == INVALID_SLOT)
    {
        for (size_t i = 0; i != m_placed.size(); ++i)
        {
            if (!m_placed[i])
            {
                maxCell.id = i;
                m_placed[i] = true;
                break;
            }
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

        for (size_t i = mid, j = mid; i >= 0 && j < size; --i, ++j)
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
