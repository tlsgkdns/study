#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int IQ[51];
list<pair<int, int>> arr;
int N, ans = -1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> IQ[i];
	if (N > 1)
		for (int i = -1000; i <= 1000; i++)
			arr.push_back({ i, IQ[1] - i * IQ[0] });

	for (int i = 0; i < N - 1; i++)
	{
		auto it = arr.begin();
		while (it != arr.end())
		{
			if (((*it).first * IQ[i] + (*it).second) != IQ[i + 1])
				it = arr.erase(it);
			else
				++it;
		}
	}
	if (N == 1) cout << "A\n";
	else if (arr.empty()) cout << "B\n";
	else
	{
		ans = arr.front().first * IQ[N - 1] + arr.front().second;
		bool f = false;
		for (auto it = arr.begin(); it != arr.end(); it++)
			if (ans != (*it).first * IQ[N - 1] + (*it).second)
			{
				f = true;
				break;
			}
		if (f) cout << "A\n";
		else cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1111