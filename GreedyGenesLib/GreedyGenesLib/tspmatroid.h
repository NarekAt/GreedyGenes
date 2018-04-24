#ifndef TSPMATROID_H
#define TSPMATROID_H

#include "Matroid.h"

class TSPMatroid : public IMatroid<TSPMatroidParams>
{
public:
    void ReadInputDataFromFile(const std::string& filePath) override;

    bool IsIndependentSubset(TSPMatroidParams::CollectionType& elems) const override;

    TSPMatroidParams::CollectionType& GetGroundElements() const override;

    TSPMatroidParams::SubSetsSet& GetIndependentSubsets() const override;

private:
    mutable TSPMatroidParams::CollectionType m_groundSet;
    mutable std::shared_ptr<TSPMatroidParams::SubSetsSet> m_graph;
};

#endif // TSPMATROID_H
