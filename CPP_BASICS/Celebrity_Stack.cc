#include <iostream>
#include <stack>
#include  <vector>

int celebrity(std::vector<std::vector<int>>& mat)
{
	int n = mat.size();

	std::stack<int> st;
	
	for (int i = 0; i < n; i++)
				st.push(i);

	while(st.size() > 1) {

			int a = st.top();
			st.pop();

			int b = st.top();
			st.pop();

			std::cout << "a b" << a << " " << b << "\n ";

			if (mat[a][b]) {
					st.push(b);
			} else {
					st.push(a);
			}
	}
	
	int c = st.top();
	st.pop();

	for (int i = 0; i < n; i++) {
			if (i == c) continue;
			if (mat[c][i] || !mat[i][c])
				return -1;
	}

	return c;
}


int main()
{
	std::vector<std::vector<int>> mat = {
			{0, 1, 0},
			{0, 0, 0},
			{0, 1, 0},
	};


	std::cout << celebrity(mat);

	return 0;
}

