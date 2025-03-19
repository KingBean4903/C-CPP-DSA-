// Find the squar root of a number

// Intuition
// the solution is monotonic 
// We use Binary Search
 
float squareRoot(int number, int precision)
{
	int start = 0;
	int end = number;
	int mid;

	while  (start <= end) {
		int mid = (start + end) / 2;

		if (mid * mid == number)
			ans = mid;
			return;
		
		if (mid * mid < number)
			ans = mid;
			start = mid  + 1;
		else
			end = mid  - 1;
	}	

	float increments  = 0.1;
	for (int i = 0; i < precision; i++)
	{
		while (ans * ans <= number) {
			ans += increments;
		}

		ans = ans - increments;
		increment = increments/10;
	}

	return ans;


}
