#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
	queue<long long> dist;
	queue<long long> oil;
	string tmp;
	long long n, answer = 0;
	cin >> n;
	getline(cin, tmp);
	getline(cin, tmp);
	istringstream iss(tmp);
	for (int i = 0; i < n - 1; i++)
	{
		string sub;
		iss >> sub;
		dist.push(stoi(sub));
	}

	getline(cin, tmp);
	istringstream is(tmp);
	for (int i = 0; i < n; i++)
	{
		string sub;
		is >> sub;
		oil.push(stoi(sub));
	}

	long long min = oil.front();
	oil.pop();
	answer += dist.front() * min;
	dist.pop();

	while (!dist.empty())
	{
		if (!oil.empty() && oil.front() <= min)	min = oil.front();
		oil.pop();
		answer += dist.front() * min;
		dist.pop();
	}
	cout << answer << endl;

	return 0;
}

// https://www.acmicpc.net/problem/13305

/*
greedy problem.
*/