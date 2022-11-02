#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tmp;
int P[15], F[15], S[15], V[15], C[15];
int N, mp, mf, ms, mv, s = 0, a = 1000000000;
vector<vector<int>> can;
void solve(int idx)
{
	if (idx == N)
	{
		if (mp <= 0 && mf <= 0 && ms <= 0 && mv <= 0)
		{
			if (a > s)
			{
				can = vector<vector<int>>();
				can.push_back(tmp);
				a = s;
			}
			if (a == s)
				can.push_back(tmp);
		}
		return;
	}
	mp -= P[idx]; mf -= F[idx];
	ms -= S[idx]; mv -= V[idx];
	tmp.push_back(idx + 1);
	s += C[idx];
	solve(idx + 1);
	mp += P[idx]; mf += F[idx];
	ms += S[idx]; mv += V[idx];
	s -= C[idx];
	tmp.pop_back();
	solve(idx + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++)
		cin >> P[i] >> F[i] >> S[i] >> V[i] >> C[i];
	solve(0);
	sort(can.begin(), can.end());
	if (can.size() == 0) cout << -1 << '\n';
	else
	{
		cout << a << '\n';
		for (int i = 0; i < can[0].size(); i++)
			cout << can[0][i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/19942