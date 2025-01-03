#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

std::vector<std::vector<int>> create_adjacency_matrix(
		std::unord:ered_map<std::string, std::vector<string>> graph
		) {

	std::vector<std::string> vertices;

	for (const auto& pair: graph) {
		
		vertices.push_back(pair.first);
	}

	std::sort(vertices.begin(), vertices.end());
	int num_vertices = vertices.size();


	std::vector<std::vector<int>> adj_matrix(
				num_vertices, std::vector<int>(num_vertices, 0));

	for (int i = 0; i < num_vertices; ++i) {
		
		for (const auto& neigbour: graph[vertices[i]]) {

			int j = std::distance(
						vertices.begin(),
						std::find(vertices.begin(), vertices.end(),
								neighbour));
			adj_matrix[i][j] = 1;

		}
	}
	return adj_matrix;
}


int main() {

	std::unordered_map<std::string, 
						std::vector<std::string>>
			graph = {
					{ "1", { "2" } },
					{ "2", { "3" } },
					{ "3", { "4" } },
					{ "4", { "1" }} };

	std::vector<std::vector<int>> adj_matrix = 
		create_adjacency_matrix(graph);

	for (const auto& row: adj_matrix) {
		
		for (int value: row) {
				
				std::cout << value << " ";
				
		}
		std::cout << std::endl;
	}
	
	return 0;
}
