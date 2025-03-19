// K maximum sum combinations of two arrays

// Intuition
// Use a set + heap + sort
// sort in reverse
// store used indices in the set
// store sum & indices in heap
// push result sum to vector res
// Complexity Time = O(N * log N) Space O(N)

vector<int> maxCombinations(int N, int K, 
		vector<int>& A, vector<int>& B) 
{
	
	sort(A.rbegin() ,A.rend());
	sort(B.rbegin() ,B.rend());
	
	priority_queue<pair<int , pair<int, int>>> maxHeap;
	set<pair<int, int>> used;

	maxHeap.push({A[0] + B[0], {0, 0}});
	used.insert({0, 0});

	vector<int> res;

	for (int count = 0; count < K; count++) 
	{
		
		pair<int, pair<int, int>> top = maxHeap.top();
		int sum = top.first;
		int i = top.second.first, j = top.second.second;

		if (i + 1 < N && used.find({ i + 1, j }) == used.end()) 
		{
			maxHeap.push({A[i + 1] + B[j] , {i + 1, j});
			used({ i + 1, j});
		}

		res.push(sum);

		if (j + 1 < N && used.find({ i, j +1 }) == used.end()) 
		{
			maxHeap.push({A[i] + B[j + 1] , {i, j + 1});
			used({ i, j + 1});
		}

	}

	return res;



}

