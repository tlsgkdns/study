#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll N, M, K, L = -1, R = 0;
ll V[200001], C[200001];

bool solve(ll l)
{
	vector<int> arr;
	ll s = 0;
	for (int i = 0; i < K; i++)
	{
		if (C[i] > l) continue;
		arr.push_back(-V[i]);
	}
	if (arr.size() < N) return false;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) s += -arr[i];
	return (s >= M);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V[i] >> C[i];
		R = max(R, C[i]);
	}
	while (L + 1 < R)
	{
		int m = (L + R) / 2;
		if (solve(m)) R = m;
		else L = m;
	}
	if (!solve(R)) R = -1;
	cout << R << '\n';
}

// https://www.acmicpc.net/problem/17503