#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, H, K;
vector<pair<int, int>> p;
multiset<int> S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> H >> K;
		p.push_back({ -H, K });
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < N; i++)
	{
		auto iter = S.lower_bound(p[i].second);
		if (iter == S.begin()) S.insert(1);
		else
		{
			--iter;
			int tmp = (*iter) + 1;
			S.erase(iter);
			S.insert(tmp);
		}
	}
	cout << S.size() << '\n';
}

// https://www.acmicpc.net/problem/19700