#ifndef TSPGRAPH_H
#define TSPGRAPH_H

#include <vector>
#include <map>

class TSPGraph
{
private:
    int V; // number of vertices
    int total_edges; // total of edges
    int initial_vertex; // initial vertex
    std::map<std::pair<int, int>, int> map_edges; // map of the edges
public:
    TSPGraph(int V, int initial_vertex, bool random_graph = false); // constructor
    void addEdge(int v1, int v2, int weight); // adds a edge
    void showGraph(); // shows all the links of the graph
    void generatesGraph(); // generates a random graph
    void showInfoGraph(); // shows info of the graph
    int existsEdge(int src, int dest); // checks if exists a edge
};

typedef std::pair<std::vector<int>, int> my_pair;
#endif // TSPGRAPH_H
