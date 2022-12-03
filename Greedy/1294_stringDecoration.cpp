#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int idx = 0, N;
vector<string> words;
string str, ans;
struct cmp
{
	bool operator()(pii p1, pii p2)
	{
		int L1 = p1.first, idx1 = p1.second;
		int L2 = p2.first, idx2 = p2.second;
		if (words[L1][idx1] == words[L2][idx2])
		{
			string S1(words[L1].begin() + idx1, words[L1].end()), S2(words[L2].begin() + idx2, words[L2].end());
			for (int i = 0; i < min(S1.size(), S2.size()); i++)
				if (S1[i] != S2[i])
					return S1[i] > S2[i];
			return S1.size() < S2.size();
		}
		return words[L1][idx1] > words[L2][idx2];
	}
};
priority_queue<pii, vector<pii>, cmp> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		words.push_back(str);
	}
	for (int i = 0; i < N; i++) pq.push({ i, 0 });
	while (!pq.empty())
	{
		int L = pq.top().first;
		int here = pq.top().second;
		ans.push_back(words[L][here]);
		pq.pop();
		if (here + 1 < (int)words[L].size()) pq.push({ L, here + 1 });
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1294