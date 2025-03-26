// Find K closest points to origin

int squared(vector<int>& point)
{
	return point[0] * point[0] + 
			point[1] * point[1];
}

vector<vector<int>> closeset(vector<vector<int>>& arr, int k)
{
  int n = arr.size();

  priority_queue<pair<int, vector<int>>> pq;

  for (int i = 0; i < n; i++)
  {
	int dist = squaredDist(points[i]);
	
	if (pq.size() < k )
	{
		pq.push({ dist, points[i] });
	} else {
			if (dist < pq.top().first)
			{
				pq.pop();
				pq.push({ dist, points[i] });
		}
	}

  }

  vector<vector<int>> ans;
  while(!pq.empty())
  { 
	 ans.push_back(pq.top().second);
	 pq.pop();
  }
	
	return ans
}
