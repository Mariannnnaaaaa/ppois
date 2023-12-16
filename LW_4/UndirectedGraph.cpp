#include "UndirectedGraph.h"

template<typename T>
UndirectedGraph<T>::UndirectedGraph(int vertices) : numVertices(vertices), numEdges(0), adjList(vertices) {}

template<typename T>
UndirectedGraph<T>::UndirectedGraph() : numVertices(0), numEdges(0), adjList(0) {}

template<typename T>
UndirectedGraph<T>::UndirectedGraph(const UndirectedGraph& other)
    : numVertices(other.numVertices), numEdges(other.numEdges), adjList(other.adjList) {}

template<typename T>
UndirectedGraph<T>::~UndirectedGraph() {}

template<typename T>
bool UndirectedGraph<T>::isEmpty() const {
    return numVertices == 0;
}

template<typename T>
void UndirectedGraph<T>::clear() {
    adjList.clear();
    numVertices = 0;
    numEdges = 0;
}

template<typename T>
UndirectedGraph<T>& UndirectedGraph<T>::operator=(const UndirectedGraph& other) {
    if (this != &other) {
        numVertices = other.numVertices;
        numEdges = other.numEdges;
        adjList = other.adjList;
    }
    return *this;
}

template<typename T>
bool UndirectedGraph<T>::operator==(const UndirectedGraph& other) {
    return numVertices == other.numVertices &&
        numEdges == other.numEdges &&
        adjList == other.adjList;
}

template<typename T>
bool UndirectedGraph<T>::operator!=(const UndirectedGraph& other) {
    return !(*this == other);
}

template<typename T>
bool UndirectedGraph<T>::operator>(const UndirectedGraph& other) {
    return numVertices > other.numVertices ||
        (numVertices == other.numVertices && numEdges > other.numEdges);
}

template<typename T>
bool UndirectedGraph<T>::operator<(const UndirectedGraph& other) {
    return numVertices < other.numVertices ||
        (numVertices == other.numVertices && numEdges < other.numEdges);
}

template<typename T>
bool UndirectedGraph<T>::operator>=(const UndirectedGraph& other) {
    return !(*this < other);
}

template<typename T>
bool UndirectedGraph<T>::operator<=(const UndirectedGraph& other) {
    return !(*this > other);
}

template<typename T>
void UndirectedGraph<T>::addVertex() {
    adjList.push_back(VertexList<T>());
    numVertices++;
}

template<typename T>
void UndirectedGraph<T>::addEdge(int v, int w) {
    if (v >= numVertices || w >= numVertices) {
        throw runtime_error("One of the vertices does not exist.\n");
        return;
    }
    adjList[v].push_back(w);
    adjList[w].push_back(v);
    numEdges++;
}

template<typename T>
bool UndirectedGraph<T>::hasVertex(int v) const {
    return (v < numVertices);
}

template<typename T>
bool UndirectedGraph<T>::hasEdge(int v, int w) {
    if (!hasVertex(v) || !hasVertex(w)) return false;
    for (T adj : adjList[v]) {
        if (adj == w) return true;
    }
    return false;
}

template<typename T>
int UndirectedGraph<T>::getVertexCount() {
    return numVertices;
}

template<typename T>
int UndirectedGraph<T>::getEdgeCount() {
    return numEdges;
}

template<typename T>
int UndirectedGraph<T>::getVertexDegree(int v) {
    if (!hasVertex(v)) return 0;
    return adjList[v].size();
}

template<typename T>
void UndirectedGraph<T>::printGraph() {
    for (int v = 0; v < numVertices; ++v) {
        cout << "Vertex Adjacency list " << v << ": ";
        for (T w : adjList[v]) {
            cout << w << " ";
        }
        cout << endl;
    }
}

template<typename T>
void UndirectedGraph<T>::removeVertex(int v) {
    if (!hasVertex(v)) return;
    for (int i = 0; i < adjList.size(); i++) {
        adjList[i].remove(v);
    }
    adjList.erase(adjList.begin() + v);
    numVertices--;
}

template<typename T>
void UndirectedGraph<T>::removeEdge(int v, int w) {
    if (!hasEdge(v, w)) return;
    adjList[v].remove(w);
    adjList[w].remove(v);
    numEdges--;
}

template<typename T>
typename AdjacencyList<T>::iterator UndirectedGraph<T>::vertex_begin() { return adjList.begin(); }
template<typename T>
typename AdjacencyList<T>::iterator UndirectedGraph<T>::vertex_end() { return adjList.end(); }
template<typename T>
typename AdjacencyList<T>::const_iterator UndirectedGraph<T>::vertex_begin() const { return adjList.cbegin(); }
template<typename T>
typename AdjacencyList<T>::const_iterator UndirectedGraph<T>::vertex_end() const { return adjList.cend(); }

template<typename T>
vector<pair<int, typename VertexList<T>::iterator>> UndirectedGraph<T>::edge_begin() {
    vector<pair<int, typename VertexList<T>::iterator>> edges;
    for (int i = 0; i < numVertices; ++i) {
        for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it) {
            if (i < *it) {
                edges.push_back(make_pair(i, it));
            }
        }
    }
    return edges;
}

template<typename T>
typename VertexList<T>::iterator UndirectedGraph<T>::incident_edges_begin(int v) {
    if (!hasVertex(v)) return VertexList<T>::iterator();
    return adjList[v].begin();
}

template<typename T>
typename VertexList<T>::iterator UndirectedGraph<T>::incident_edges_end(int v) {
    if (!hasVertex(v)) return VertexList<T>::iterator();
    return adjList[v].end();
}

template<typename T>
typename VertexList<T>::iterator UndirectedGraph<T>::adjacent_vertices_begin(int v) {
    if (!hasVertex(v)) return VertexList<T>::iterator();
    return adjList[v].begin();
}

template<typename T>
typename VertexList<T>::iterator UndirectedGraph<T>::adjacent_vertices_end(int v) {
    if (!hasVertex(v)) return VertexList<T>::iterator();
    return adjList[v].end();
}

template<typename T>
void UndirectedGraph<T>::removeVertex(typename AdjacencyList<T>::iterator vertexIt) {
    int v = distance(adjList.begin(), vertexIt);
    if (!hasVertex(v)) throw runtime_error("The vertex to delete was not found.");
    for (auto& list : adjList) list.remove(v);

    adjList.erase(vertexIt);
    numVertices--;

    for (auto& list : adjList) {
        for (auto& vertex : list) {
            if (vertex > v) vertex--;
        }
    }
}

template<typename T>
void UndirectedGraph<T>::removeEdge(int v, typename VertexList<T>::iterator edgeIt) {
    if (v < 0 || v >= numVertices) throw runtime_error("The vertex to delete was not found.");
    if (edgeIt == adjList[v].end()) throw runtime_error("The iterator does not point to an existing edge.");
    int w = *edgeIt;
    if (w < 0 || w >= numVertices)  throw runtime_error("The vertex w does not exist in the graph.");
    adjList[v].erase(edgeIt);
    for (auto it = adjList[w].begin(); it != adjList[w].end(); ++it) {
        if (*it == v) {
            adjList[w].erase(it);
            break;
        }
    }
    numEdges--;
}

template<typename T>
typename AdjacencyList<T>::reverse_iterator UndirectedGraph<T>::vertex_rbegin() { return adjList.rbegin(); }
template<typename T>
typename AdjacencyList<T>::reverse_iterator UndirectedGraph<T>::vertex_rend() { return adjList.rend(); }
template<typename T>
typename AdjacencyList<T>::const_reverse_iterator UndirectedGraph<T>::vertex_rbegin() const { return adjList.crbegin(); }
template<typename T>
typename AdjacencyList<T>::const_reverse_iterator UndirectedGraph<T>::vertex_rend() const { return adjList.crend(); }

template<typename T>
typename VertexList<T>::reverse_iterator UndirectedGraph<T>::incident_edges_rbegin(int v) {
    if (!hasVertex(v)) return typename VertexList<T>::reverse_iterator();
    return typename VertexList<T>::reverse_iterator(adjList[v].rbegin());
}

template<typename T>
typename VertexList<T>::reverse_iterator UndirectedGraph<T>::incident_edges_rend(int v) {
    if (!hasVertex(v)) return typename VertexList<T>::reverse_iterator();
    return typename VertexList<T>::reverse_iterator(adjList[v].rend());
}

template<typename T>
typename VertexList<T>::const_reverse_iterator UndirectedGraph<T>::incident_edges_rbegin(int v) const {
    if (!hasVertex(v)) return typename VertexList<T>::const_reverse_iterator();
    return typename VertexList<T>::const_reverse_iterator(adjList[v].crbegin());
}

template<typename T>
typename VertexList<T>::const_reverse_iterator UndirectedGraph<T>::incident_edges_rend(int v) const {
    if (!hasVertex(v)) return typename VertexList<T>::const_reverse_iterator();
    return typename VertexList<T>::const_reverse_iterator(adjList[v].crend());
}