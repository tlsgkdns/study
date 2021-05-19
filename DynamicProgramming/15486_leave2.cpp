#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> time, cache, salary;
int n, t, s;
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
	cin >> n;
	cache.resize(n, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> t >> s;
		time.push_back(t);
		salary.push_back(s);
	}
	cout << work(0, n) << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/15486