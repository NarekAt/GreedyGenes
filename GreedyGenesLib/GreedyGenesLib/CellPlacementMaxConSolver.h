#pragma once
#include "GreedySDK.h"
#include "GreedyStrategy.h"

class CellPlacementMaxConSolver : public GreedyStrategy<CellPlacementMatroidParams>
{
public:
    CellPlacementMaxConSolver(const std::string& fileName, CellPlacementMatroidParams& params);

    MatroidPtr GetProblemMatroid() override;

    CellPlacementMatroidParams& GetParams() override;

    void Solve() override;

    CellPlacementMatroidParams::ResultType GetResults() override;

private:
    Cell SeedCell();
    Cell SelectCell(const CellPlacementMatroidParams::ResultType& layout);
    size_t SelectSlot(Cell& cell);

private:
    MatroidPtr m_matroid;
    CellPlacementMatroidParams m_params;

    CellPlacementMatroidParams::ResultType m_result;
};
