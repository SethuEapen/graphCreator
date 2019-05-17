#include <iostream>;

class Graph {
	private:
		struct Vertex {
			char label;
		}
		int matrix[20][20];
		Graph();
		Vertex vertisies[20];
		void printMatrix();
		void addEdge(Vertex*, Vertex*, bool);
		Vertex* findVertex();
	private:
}