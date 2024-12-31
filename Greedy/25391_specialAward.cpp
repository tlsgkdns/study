#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

vector<pair<int, int>> score;
int N, M, K, a, b;
priority_queue <ll> pq;
vector<int> arr;
ll ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		score.push_back({ -b, a });
	}
	sort(score.begin(), score.end());
	for (int i = 0; i < K; i++) ans += score[i].second;
	for (int i = K; i < N; i++)
		arr.push_back(-score[i].second);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < M; i++) ans -= arr[i];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25391