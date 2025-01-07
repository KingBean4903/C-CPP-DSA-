#include <iostream>
#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;

class AdjListNode 
{
	
	int v;
	int weight;

	public:
		AdjListNode(int _v, int _w) { v _v; weight = _W; }
		int getV() { return _v; }
		int getWeight() { return weight; }

};

class Graph
{
	
	int v;
	list<AdjListNode> *adj;
	void topologicalSortUtil(int  v, bool visited, Stack<int>& stack);

	public:
		Graph(int v);
		void addEdge(int u, int v, int weight);
		void shortestPath(int s);

};

Graph::Graph(int v) {

	this->v = v;
	adj = new list<AdjListNode>[v];

}

void Graph::addEdge(int u, int v, int weight) {

	AdjListNode node(v, weight);
	adj[u].push_back(node);

}

void topologicalSortUtil(int v, bool visited[], 
		stack<int> &Stack) {
	
	visited[v] = true;
	list<AdjListNode>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {

		AdjListNode node = *i;
		if (!visited[node.getV()])
				topologicalSortUtil(node.getV(), visited, Stack)
	}
	
	Stack.push(u);

}

void Graph::shortestPath(int s) {

	stack<int> Stack;
	int dist[V];

	bool *visited = new bool[V];
	for (int i = 0; i <V; i++)
			visited[i] = false;

	for (int i = 0; i < V; i++)
			if (visited[i] == false)
				topologicalSortUtil(i, visited, Stack);

	for (int i = 0; i < V; i++)
			dist[i] = INF;
	dist[s] = 0;

	while (Stack.empty() == false)
	{

		int u = Stack.pop();
		Stack.pop();

		list<AdjListNode>::iterator i;
		if (dist[u] != INF)
		{
			for (i = adj[u].begin(); i != adj[u].end(); ++i)
				if (dist[i->getV()] > dist[u] + i.getWeight())
						dist[i->getV()] = dist[u] + i->getWeight();
		}
	}

	for (int i = 0; i < V; i++)
		(dist[i] == INF) ? cout << "INF ": cout << dist[i] << " ";

}

int main() {
	
	Graph g(6);

	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 1, 5);
	
	int s = 1;
	cout << "Following are shortest distances from source " << s << " n";
	g.shortestPath(s);

	return 0;
}
