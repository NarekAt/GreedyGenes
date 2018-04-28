#ifndef RESULTWRITERS_H
#define RESULTWRITERS_H

#include "resultwritter.h"
#include "GreedySDK.h"
#include <cassert>
#include <fstream>
#include <QtMath>

class CellPlacementResultWritter : public IResultWritter
{
public:
    std::string write(std::vector<uint64_t>& res) override
    {
        const std::string fileName = "cell_placement.out";
        assert(!res.empty());

        std::ofstream out;
        out.open(fileName);

        out << "CELL PLACEMENT" << "\n" << "\n";

        const size_t n = qSqrt(res.size());

        size_t j = res.size() - 1;

        for (size_t i = 0; i != n; ++i)
        {
            for (int k = 0; k != n; ++k)
            {
                out << res[j--] << " ";
            }
            out << "\n";
        }

        return fileName;
    }
};

#endif // RESULTWRITERS_H
