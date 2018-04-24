#include "tspmatroid.h"
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

void TSPMatroid::ReadInputDataFromFile(const std::string &filePath)
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

    rapidjson::Value& roads = fileJson["ROADS"];
    assert(roads.IsArray());
    auto numOfCities = fileJson["NUM_OF_CITIES"].GetInt();

    m_graph = std::make_shared<Graph>(numOfCities, 0, true);

    for (rapidjson::SizeType i = 0; i < roads.Size(); ++i)
    {
        const auto& road = roads[i].GetObject();

        int source = road["SOURCE"].GetInt();
        int dest = road["DEST"].GetInt();
        int w = road["WEIGHT"].GetInt();

        m_graph->addEdge(source, dest, w);
    }
}

bool TSPMatroid::IsIndependentSubset(TSPMatroidParams::CollectionType & elems) const
{
    return false;
}

TSPMatroidParams::CollectionType& TSPMatroid::GetGroundElements() const
{
    return m_groundSet;
}

TSPMatroidParams::SubSetsSet& TSPMatroid::GetIndependentSubsets() const
{
    return *m_graph;
}
