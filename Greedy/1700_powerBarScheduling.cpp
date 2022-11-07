#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pos[101], order;
int N, K, arr[101], ans = 0, idx[101];
bool v[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		pos[arr[i]].push_back(i);
	}
	for (int i = 0; i <= K; i++)
		pos[i].push_back(K + 1);
	for (int i = 0; i < K; i++)
	{
		idx[arr[i]]++;
		if (v[arr[i]]) continue;
		sort(order.begin(), order.end(), [](int a, int b) {return pos[a][idx[a]] < pos[b][idx[b]]; });
		if ((int)order.size() == N)
		{
			v[order.back()] = false;
			order.pop_back();
			ans++;
		}
		v[arr[i]] = true;
		order.push_back(arr[i]);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1700