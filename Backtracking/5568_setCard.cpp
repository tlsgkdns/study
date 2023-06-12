#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> um;
vector<int> arr;
int N, K, C[11], ans = 0;
bool v[11];

void solve()
{
	if (arr.size() == K)
	{
		int h = 1, n = 0;
		for (int i = 0; i < K; i++)
		{
			n += h * arr[i];
			if ((arr[i] / 10) > 0) h *= 100;
			else h *= 10;
		}
		if (um.count(n) == 0) um.insert({ n, true });
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (v[i]) continue;
		arr.push_back(C[i]);
		v[i] = true;
		solve();
		v[i] = false;
		arr.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> C[i];
	solve();
	cout << um.size() << '\n';
}

// https://www.acmicpc.net/problem/5568