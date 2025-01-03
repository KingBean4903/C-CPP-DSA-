#include <bits/stdc++.h>

using namespace std;


void addEdge(vector<vector<int>> &adj, int u, int v) {
	
	adj[u].push_back(v);

}

bool isCyclic(int V, vector<vector<int>>& adj) {

	vector<int> inDegree(V, 0);

	queue<int> q;

	int visited = 0;

	for (int i = 0; i < V; i++) {
		for (auto k : adj[i]) {
				inDegree[k]++;
		}
	}

	for (int j = 0; j < V; j++) {
		if (inDegree[j] == 0) {
				q.push(j);
		}
	}

	while (!q.empty()) {
			
		int node = q.front();
		q.pop();
		visited++;

		for (auto x : adj[node]) {
				
				inDegree[x]--;

				if (inDegree[x] == 0) {
							q.push(x);
				}
		}
	
		
	}

	return V != visited;

}



int main() {
	
	int V = 6;

	vector<vector<int>> adj(V);

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 4, 1);
	addEdge(adj, 4, 5);
	addEdge(adj, 5, 3);

	if (isCyclic(V, adj)) {
			cout << "Contains cycle " << endl;
	} else {
			cout << "No cycle" << endl;
	}

	return 0;
}
