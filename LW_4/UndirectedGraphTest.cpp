#include "pch.h"
#include "CppUnitTest.h"
#include "../UndirectedGraph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UndirectedGraphTest
{
	TEST_CLASS(UndirectedGraphTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
                UndirectedGraph g(5);
                g.addEdge(0, 1);
                g.addEdge(0, 4);
                g.addEdge(1, 2);
                g.addEdge(1, 3);
                g.addEdge(1, 4);
                g.addEdge(2, 3);
                g.addEdge(3, 4);

                g.printGraph();

                cout << "Number of vertices: " << g.getVertexCount() << endl;
                cout << "Number of edges: " << g.getEdgeCount() << endl;
                cout << "The degree of the 1 vertex: " << g.getVertexDegree(1) << endl;
                cout << "The presence of a 5 vertex: " << (g.hasVertex(5) ? "Yes" : "No") << endl;
                cout << "The presence of an edge between vertices 0 and 1: " << (g.hasEdge(0, 1) ? "Yes" : "No") << endl;

                g.removeEdge(1, 2);
                cout << "The degree of the 1 vertex: " << g.getVertexDegree(1) << endl;

                for (auto it = g.vertex_begin(); it != g.vertex_end(); ++it) {
                    std::cout << "Vertex: " << std::distance(g.vertex_begin(), it) << endl;
                }

                auto edges = g.edge_begin();
                for (const auto& edge : edges) {
                    cout << "Edge: (" << edge.first << ", " << *edge.second << ")" << endl;
                }

                int vertex = 1;
                std::cout << "Edges incident to the vertex " << vertex << ": ";
                for (auto it = g.incident_edges_begin(vertex); it != g.incident_edges_end(vertex); ++it) {
                    cout << *it << " ";
                }
                cout << endl;

                cout << "Vertices adjacent to a vertex " << vertex << ": ";
                for (auto it = g.adjacent_vertices_begin(vertex); it != g.adjacent_vertices_end(vertex); ++it) {
                    cout << *it << " ";
                }
                cout << endl;

                cout << "\n\n\n";
                g.printGraph();

                auto vertexIt = g.vertex_begin();
                advance(vertexIt, 2);
                g.removeVertex(vertexIt);

                cout << "\n\n\n";
                g.printGraph();

                auto edgeIt = g.incident_edges_begin(vertex);
                advance(edgeIt, 1);
                g.removeEdge(vertex, edgeIt);

                cout << "\n\n\n";
                g.printGraph();

                for (auto it = g.vertex_rbegin(); it != g.vertex_rend(); ++it) {
                    // Доступ к вершинам через обратный итератор
                }

                for (auto it = g.incident_edges_rbegin(vertex); it != g.incident_edges_rend(vertex); ++it) {
                    // Доступ к рёбрам через обратный итератор
                }

                int res = 4;
                int result = g.getVertexCount();
                Assert::AreEqual(result, res);
		}
        TEST_METHOD(TestMethod2)
        {
            UndirectedGraph g1(5);
            g1.addEdge(0, 1);
            g1.addEdge(0, 4);
            g1.addEdge(1, 2);
            g1.addEdge(1, 3);
            g1.addEdge(1, 4);
            g1.addEdge(2, 3);
            g1.addEdge(3, 4);
            g1.removeVertex(2);

            UndirectedGraph g2(5);
            g2.addEdge(0, 1);
            g2.addEdge(0, 4);
            g2.addEdge(1, 2);
            g2.addEdge(1, 3);
            g2.addEdge(1, 4);
            g2.addEdge(2, 3);

            bool res = g1 > g2;
            g1 < g2;
            g1 == g2;
            g1 >= g2;
            g1<=g2;
            bool result = false;
            Assert::AreEqual(result, res);
        }
	};
}
