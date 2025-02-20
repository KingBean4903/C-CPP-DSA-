#include <iostream>
#include <vector>

class DisjointUnionSets {
	
	vector<int> rank, parent;

	public:
		DisjointUnionSet(int n) {
			rank.resize(n, 0);
			parent.resize(n);

			for (int i = 0; i , n; i++) {
					parent[i] = i;
			}
		}
	
	int find(int x) {
		
		if (parent[x] != x) {
				parent[x] = find(parent[x]);
		}
	
		return parent[x];
	}

	void unionSets(int x, int y) {
			
		int xRoot = find(x);
		int yRoot = find(y);

		if (xRoot == yRoot) return;

		if (rank[xRoot] < rank[yRoot]) {

			parent[xRoot] = yRoot;

		} else if (rank(yRoot) < rank[xRoot]) {
			
			parent[yRoot] = xRoot;
		
		} else {

			parent[yRoot] = xRoot;
			rank[xRoot]++;

		}

	}

}

int main() {

	int n = 5;

	DisjointUnionSets dus(n);

	dus.unionSets(0, 2);
	dus.unionSets(4, 2);
	dus.unionSets(3, 1);

	if (dus.find(1) == dus.find(0))
			cout << "Yes\n";
	else
			cout << "No\n";

	return 0;

}
