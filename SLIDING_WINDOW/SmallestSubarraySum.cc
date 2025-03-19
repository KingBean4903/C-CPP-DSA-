// Smallest subarry with sum greater
// than given value

int smallest(vector<int>& arr, int x
{
 
 int n = arr.size();
 int i = 0, j = 0, sum = 0;
 int ans = INT_MAX;
 

 while (j < n) {

	while (j < n && sum <= x)
		sum += arr[j++];
	
	if (j == n && sum <= x) break;

	while (i < j && sum - arr[i] > x)
		sum -= arr[i++];

	ans = min(ans, j - i);
	sum -= arr[i];
	i++;
 }
 
 if (ans == INT_MAX) return 0;

 return ans;

}




























