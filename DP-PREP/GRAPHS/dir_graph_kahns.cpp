#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>>& adj, int V) {

	vector<int> indegree(V);
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
					indegree[it]++;
		}
	}
	
	queue<int> q;
	for (int i = 0; i< V; i++) {
			if (indegree[i] == 0) {
					q.push(i);
			}
	}

	vector<int> result;
	while(!q.empty()) {
		int node = q.front();

		q.pop();
		result.push_back(node);
	
		for (auto it: adj[node]) {
				indegree[it]--;

				if (indegree[it] == 0)
						q.push(it);
		}
	}

	if (result.size() != V) {

		cout << "Graph contains cycle" << endl;
		return {};
	}
	
	return result;

}


int main() {

	int V = 6;

	vector<vector<int>> edges = 
	{
		{0 , 1}, {1, 2}, {2, 3},
		{4, 5}, {5, 1}, {5, 2} 
	};

	vector<vector<int>> adj(V);
	
	for (auto i : edges) {
		adj[i[0]].push_back(adj[i[1]]);
	}

	cout << "Topological sorting in the graph";
	vector<int> result = topologicalSort(adj, V);

	for (auto i: result) {
		cout << i << " ";
	}

	return 0;
}

