#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> S;
int N, L, A, B, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (A > B) swap(A, B);
		S.push_back({ A, B });
	}
	sort(S.begin(), S.end());
	int here = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].second < here) continue;
		if (S[i].first > here) here = S[i].first;
		int l = S[i].second - S[i].first - (here - S[i].first);
		ans += (l / L);
		if (l % L > 0)
		{
			here = S[i].second - (l % L) + L;
			++ans;
		}
		else
			here = S[i].second;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1911