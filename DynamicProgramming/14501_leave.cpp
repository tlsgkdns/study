#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> time;
vector<int> salary;
int cache[15];

int work(int day, int retire)
{
	if (day >= retire) return 0;
	int& ret = cache[day];
	if (ret != -1) return ret;

	int workDay = day + time[day];

	if (workDay > retire)
		ret = work(day + 1, retire);
	else
		ret = max(work(workDay, retire) + salary[day], work(day + 1, retire));

	return ret;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	string tmp;
	int n;
	int t, s;
	cin >> n;
	getline(cin, tmp);
	for (int i = 0; i < n; i++)
	{
		cin >> t >> s;
		getline(cin, tmp);
		time.push_back(t);
		salary.push_back(s);
	}
	int answer = work(0, n);

	cout << answer << endl;

	return 0;
}

// https://www.acmicpc.net/problem/14501

/*
easy dynamic programming.
*/