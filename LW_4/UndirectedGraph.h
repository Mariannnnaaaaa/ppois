#pragma once
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
using AdjacencyList = vector<list<T>>;

template<typename T>
using VertexList = list<T>;

template<typename T>
class UndirectedGraph {
private:
    int numVertices;
    int numEdges;
    AdjacencyList<T> adjList;

public:
    UndirectedGraph(int vertices);

    UndirectedGraph();

    UndirectedGraph(const UndirectedGraph& other);

    ~UndirectedGraph();

    bool isEmpty() const;

    void clear();

    UndirectedGraph& operator=(const UndirectedGraph& other);

    bool operator==(const UndirectedGraph& other);

    bool operator!=(const UndirectedGraph& other);

    bool operator>(const UndirectedGraph& other);

    bool operator<(const UndirectedGraph& other);

    bool operator>=(const UndirectedGraph& other);

    bool operator<=(const UndirectedGraph& other);

    void addVertex();

    void addEdge(int v, int w);

    bool hasVertex(int v) const;

    bool hasEdge(int v, int w);

    int getVertexCount();

    int getEdgeCount();

    int getVertexDegree(int v);

    void printGraph();

    void removeVertex(int v);

    void removeEdge(int v, int w);

    typename AdjacencyList<T>::iterator vertex_begin();
    typename AdjacencyList<T>::iterator vertex_end();
    typename AdjacencyList<T>::const_iterator vertex_begin() const;
    typename AdjacencyList<T>::const_iterator vertex_end() const;

    vector<pair<int, typename VertexList<T>::iterator>> edge_begin();

    typename VertexList<T>::iterator incident_edges_begin(int v);

    typename VertexList<T>::iterator incident_edges_end(int v);

    typename VertexList<T>::iterator adjacent_vertices_begin(int v);

    typename VertexList<T>::iterator adjacent_vertices_end(int v);

    void removeVertex(typename AdjacencyList<T>::iterator vertexIt);

    void removeEdge(int v, typename VertexList<T>::iterator edgeIt);

    typedef typename AdjacencyList<T>::reverse_iterator reverse_vertex_iterator;
    typedef typename AdjacencyList<T>::const_reverse_iterator const_reverse_vertex_iterator;

    reverse_vertex_iterator vertex_rbegin();
    reverse_vertex_iterator vertex_rend();
    const_reverse_vertex_iterator vertex_rbegin() const;
    const_reverse_vertex_iterator vertex_rend() const;

    typedef typename VertexList<T>::reverse_iterator reverse_edge_iterator;
    typedef typename VertexList<T>::const_reverse_iterator const_reverse_edge_iterator;

    reverse_edge_iterator incident_edges_rbegin(int v);

    reverse_edge_iterator incident_edges_rend(int v);

    const_reverse_edge_iterator incident_edges_rbegin(int v) const;

    const_reverse_edge_iterator incident_edges_rend(int v) const;
};
