#include <iostream>
#include <deque>
#include <vector>

void rotateVector(std::vector<int>& arr, int x){

	std::deque<int> dq;

	for (int i = 0; i < arr.size(); i++)
		dq.push_back(arr[i]);
	int j = 0;

	while( j < arr.size() - 1) 
	{
		int b = dq.back();
		dq.pop_back();
		dq.pop_back();

		dq.push_front(b);
		
		j++;
	}

	std::cout << dq.back() << " ";

}

int main()
{
	std::vector<int> arr = {1, 2, 3, 4, 5};
	int x = 1;

	rotateVector(arr, x);

	return 0;


}


