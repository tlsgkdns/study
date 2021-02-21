#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int minBirth, maxBirth, minDeath, maxDeath;
	vector<int> minAge;
	vector<int> maxAge;

	while (true)
	{
		cin >> minBirth >> maxBirth >> minDeath >> maxDeath;
		if (minBirth == 0 && maxBirth == 0 && minDeath == 0 && maxDeath == 0) break;
		minAge.push_back(minDeath - maxBirth);
		maxAge.push_back(maxDeath - minBirth);
	}

	for (int i = 0; i < minAge.size(); i++)
		cout << minAge[i] << " " << maxAge[i] << endl;

	return 0;
}
// https://www.acmicpc.net/problem/10599

/*
simple problem
*/