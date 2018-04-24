#ifndef ENUMCONVERTERS_H
#define ENUMCONVERTERS_H

#include "Types.h"
#include <QString>
#include <QMap>


class EnumConverter
{
public:

    static bool FromString(const QString& str, ProblemType& e)
    {
        static const QMap<QString, ProblemType> convertionMap
        {
            { "VLSI Cell Placement", ProblemType::VLSI_CELL_PLACEMENT },
            { "VLSI Floor Planning", ProblemType::VLSI_FLOOR_PLANNING },
            { "Min alpha Cluster Cover", ProblemType::ALPHA_CLUSTER_COVER },
            { "Max k Cluster Cover", ProblemType::ALPHA_CLUSTER_COVER },
            { "Traveling Salesman", ProblemType::TRAVELING_SALESMAN }
        };

        // TODO: Move this part to a templated function to avoid code duplication.
        auto it = convertionMap.find(str);
        if (it != convertionMap.end())
        {
            e = it.value();
            return true;
        }

        return false;
    }

    static bool FromString(const QString& str, Method& e)
    {
        static const QMap<QString, Method> convertionMap
        {
            { "Greedy method (Peeling and other heuiristics)", Method::GREEDY },
            { "Genetic method", Method::GENETIC },
            { "Genetic method based on greedily generation of initial population", Method::GREEDY_GENETIC }
        };

        auto it = convertionMap.find(str);
        if (it != convertionMap.end())
        {
            e = it.value();
            return true;
        }

        return false;
    }
};


#endif // ENUMCONVERTERS_H
