#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> w1, w2;
int T, K, N, W[4][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		w1.clear(); w2.clear();
		cin >> K >> N;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < N; j++)
				cin >> W[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				w1.push_back(W[0][i] + W[1][j]);
				w2.push_back(W[2][i] + W[3][j]);
			}
		sort(w2.begin(), w2.end());
		int ans = 1000000007;
		for (int i = 0; i < w1.size(); i++)
		{
			int target = K - w1[i], l = 0, r = w2.size() - 1;
			while (l + 1 < r)
			{
				int m = (l + r) / 2;
				if (w2[m] < target) l = m;
				else r = m;
			}
			int cmp = w1[i];
			if (abs(w2[l] - target) <= abs(w2[r] - target))
				cmp += w2[l];
			else
				cmp += w2[r];
			if (abs(K - ans) > abs(K - cmp) || (abs(K - ans) == abs(K - cmp) && cmp < ans))
				ans = cmp;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9007