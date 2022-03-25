#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using bus = pair<pair<int, int>, int>;
vector<bus> L, S;
vector<int> ans;
int N, M, A, B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		if (A > B) L.push_back({ { A, -B } , i + 1 });
		else S.push_back({ {A, -B}, i + 1 });
	}
	sort(L.begin(), L.end());
	sort(S.begin(), S.end());
	int h = ((L.empty()) ? -1 : L[0].first.first), t = -1;
	for (int i = 0; i < L.size(); i++)
	{
		if (t >= -L[i].first.second) continue;
		t = -L[i].first.second;
		ans.push_back(L[i].second);
	}
	int s = 0, e = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (h != -1 && h <= S[i].first.first) continue;
		if (t >= -S[i].first.second) continue;
		if (s <= S[i].first.first && -S[i].first.second <= e) continue;
		ans.push_back(S[i].second);
		if (S[i].first.first > e) s = S[i].first.first;
		e = -S[i].first.second;
	}
	sort(ans.begin(), ans.end());
	for (int a : ans)
		cout << a << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/10165