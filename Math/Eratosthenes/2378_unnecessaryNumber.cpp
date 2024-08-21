#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100001;
int D[MAX];
vector<int> d[MAX], ans, P, mDiv;
int N, M, c[MAX], cmp[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(D, -1, sizeof(D));
	for (int i = 2; i < MAX; i++)
		if (D[i] < 0)
		{
			D[i] = i;
			P.push_back(i);
			for (int j = i + i; j < MAX; j += i)
				D[j] = i;
		}
	for (int i = 2; i < MAX; i++)
	{
		int num = i;
		while (num > 1)
		{
			d[i].push_back(D[num]);
			num /= D[num];
		}
	}
	cin >> N >> M;
	int idx = 0;
	while (M > 1)
	{
		if (M % P[idx] > 0) ++idx;
		else
		{
			M /= P[idx];
			++cmp[P[idx]];
			if (mDiv.empty() || mDiv.back() != P[idx])
				mDiv.push_back(P[idx]);
		}
	}
	for (int j = 0; j < d[M].size(); j++)
		cmp[d[M][j]]++;
	double s = N - 1, m = 1;
	for (int i = 2; i <= N; i++, s--, m++)
	{
		for (int j = 0; j < d[(int)s].size(); j++)
			c[d[(int)s][j]]++;
		for (int j = 0; j < d[(int)m].size(); j++)
			c[d[(int)m][j]]--;
		bool f = true;
		for (int j = 0; j < mDiv.size(); j++)
			if (cmp[mDiv[j]] > c[mDiv[j]])
			{
				f = false;
				break;
			}
		if (f)
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2378