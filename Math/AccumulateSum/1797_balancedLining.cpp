#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> um;
vector<pair<int, int>> F;
int N, G, X, S[1000001], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> G >> X;
		F.push_back({ X, ((G == 0) ? -1 : 1) });
	}
	F.push_back({ -1, 0 });
	sort(F.begin(), F.end());
	for (int i = 1; i <= N; i++)
		S[i] = F[i].second + S[i - 1];
	for (int i = 0; i <= N; i++)
		um[S[i]] = max(um[S[i]], i);
	for (int i = 0; i <= N; i++)
	{
		auto iter = um.find(S[i]);
		if (iter == um.end() || i >= (*iter).second) continue;
		ans = max(ans, F[(*iter).second].first - F[i + 1].first);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1797