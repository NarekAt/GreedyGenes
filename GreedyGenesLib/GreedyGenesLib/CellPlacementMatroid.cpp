#include "CellPlacementMatroid.h"
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

void CellPlacementMatroid::ReadInputDataFromFile(const std::string& filePath)
{
    std::ifstream inputStream(filePath);
    if (!inputStream.is_open())
    {
        // exception
        return;
    }

    rapidjson::IStreamWrapper isw(inputStream);

    rapidjson::Document fileJson;

    fileJson.ParseStream(isw);

    rapidjson::Value& cells = fileJson["CELLS"];
    rapidjson::Value& nets = fileJson["NETS"];
    assert(cells.IsArray());
    assert(nets.IsArray());

    m_groundSet.resize(cells.Size());

    for (rapidjson::SizeType i = 0; i < cells.Size(); ++i)
    {
        const auto& cell = cells[i].GetObject();

        size_t id = static_cast<size_t>(cell["id"].GetUint64());
        long w = static_cast<long>(cell["width"].GetInt64());
        long h = static_cast<long>(cell["height"].GetInt64());

        Cell c;
        c.id = id;
        c.height = h;
        c.width = w;

        m_groundSet[i] = c;
    }

    m_connMatrix.resize(cells.Size(), std::vector<size_t>(cells.Size(), 0));

    for (rapidjson::SizeType i = 0; i < nets.Size(); ++i)
    {
        const auto& net = nets[i].GetObject();

        size_t in = static_cast<size_t>(net["IN"].GetUint64());
        size_t out = static_cast<size_t>(net["OUT"].GetUint64());
        size_t weight = static_cast<size_t>(net["weight"].GetUint64());
        assert(in < cells.Size() && out < cells.Size());

        m_connMatrix[in][out] = weight;
    }
}

bool CellPlacementMatroid::IsIndependentSubset(CellPlacementMatroidParams::CollectionType & elems) const
{
    return false;
}

CellPlacementMatroidParams::CollectionType& CellPlacementMatroid::GetGroundElements() const
{
    return m_groundSet;
}

CellPlacementMatroidParams::SubSetsSet& CellPlacementMatroid::GetIndependentSubsets() const
{
    return m_connMatrix;
}
