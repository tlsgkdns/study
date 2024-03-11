#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int E[MAX], N;
bool P[MAX], C = false;
vector<int> d, pnum, comp[MAX];
pair<int, int> solve(int n)
{
	if (n <= 2) return { -1, -1 };
	int idx = 0;
	while (idx < pnum.size() && pnum[idx] <= n)
	{
		if (P[pnum[idx]] && P[n - pnum[idx]])
			return { pnum[idx], n - pnum[idx] };
		++idx;
	}
	return { -1, -1 };
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(P, true, sizeof(P));
	cin >> N;
	for (int n = 2; n * n < MAX; n++)
		if (P[n])
		{
			for (int j = n * n; j < MAX; j += n)
				P[j] = false;
		}
	for (int n = 2; n <= (MAX / 4); n++) if (P[n]) pnum.push_back(n);
	P[0] = P[1] = false;
	for (int n = 2; n <= (N / 2); n++)
	{
		if (C) break;
		pair<int, int> a = solve(n), b = solve(N - n);
		if (a.first > 0 && b.first > 0)
		{
			C = true;
			cout << a.first << " " << a.second << " " << b.first << " " << b.second << '\n';
		}
	}
	if (!C) cout << -1 << '\n';
}

// https://solved.ac/contribute/1153