// GIVEN  2 STRINGS CHECK IF THEY
// CAN BE MADE EQUAL BY INSERTING
// AT MOST ONE SENTENCE
// S1 = Start working on the project S2 = Start project
#include <deque>

bool areSimilar(string s1, string s2) 
{
	int N = s1.size();
	int M = s2.size();

	if (N == M) {
		if (S1 == S2) {
			return true;
		}
		retrun false;
	}

	std::deque<string> x, y;

	S1.push_back(' ');
	S2.push_back(' ');
	string temp = "";

	for (int i = 0; i < N + 1; i++)
	{
		if (s1[i] == ' ') {
			x.push_back(temp);
			temp = "";
		} else {
			temp += s1[i];
		}
	}
	
	for (int i = 0; i < M + 1; i++)
	{
		if (s2[i] == ' ') {
			y.push_back(temp);
			temp = "";
		} else {
			temp += s2[i];
		}
	}

	while (x.size() > 0 && y.size() > 0 &&
				x.front() == y.front()) {

			x.pop_front();
			y.pop_front();
	}

	while (x.size() > 0 && y.size() > 0 &&
				x.back() == y.back()) {

			x.pop_back();
			y.pop_back();
	}

	if (x.size() == 0 || y.size == 0)
	{
		return true;
	}

	return false;

}
