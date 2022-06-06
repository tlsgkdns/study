#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int prob[101][101], score[101];
int subm[101], last[101];
int T, n, k, m, I, id, j, s;

bool cmp(int id1, int id2)
{
	if (score[id1] != score[id2]) return score[id1] > score[id2];
	if (subm[id1] != subm[id2]) return subm[id1] > subm[id2];
	return last[id1] > last[id2];
}
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(prob, 0, sizeof(prob)); memset(subm, 0, sizeof(subm));
		memset(last, 0, sizeof(last)); memset(score, 0, sizeof(score));
		vector<int> arr;
		cin >> n >> k >> I >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> id >> j >> s;
			prob[id][j] = max(prob[id][j], s);
			last[id] = -i;
			subm[id]--;
		}
		for (int i = 1; i <= n; i++)
		{
			int S = 0;
			for (int idx = 1; idx <= k; idx++)
				S += prob[i][idx];
			score[i] = S;
			arr.push_back(i);
		}
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 0; i < n; i++)
			if (arr[i] == I)
			{
				ans.push_back(i + 1);
				break;
			}
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/3758