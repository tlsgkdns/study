#include <iostream>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

unordered_map<string, double> R;
unordered_map<string, int> S;
string A, B;
double W, D, L;
tuple<string, string, double, double, double> arr[6];
pair<string, int> score[4];
string order[4];
bool cmp(pair<string, int> p1, pair<string, int> p2)
{
	return p1.second > p2.second;
}
void solve(int idx, double r)
{
	if (idx == 6)
	{
		vector<string> M[19];
		for (pair<string, int> p : S) M[p.second].push_back(p.first);
		bool first = true, f = false;
		for (int i = 18; i >= 0 && !f; i--)
		{
			if (M[i].empty()) continue;
			for (int idx = 0; idx < M[i].size(); idx++)
			{
				if (first)
				{
					if (M[i].size() == 1)
					{
						R[M[i][idx]] += r;
						first = false;
					}
					else
					{
						R[M[i][idx]] += (((double)2 / double(M[i].size())) * r);
						f = true;
					}
				}
				else
				{
					R[M[i][idx]] += (r / M[i].size());
					f = true;
				}
			}
		}
		return;
	}
	string c1 = get<0>(arr[idx]);
	string c2 = get<1>(arr[idx]);
	if (get<2>(arr[idx]) > 0.0)
	{
		S[c1] += 3;
		solve(idx + 1, r * get<2>(arr[idx]));
		S[c1] -= 3;
	}
	if (get<3>(arr[idx]) > 0.0)
	{
		S[c1] += 1;
		S[c2] += 1;
		solve(idx + 1, r * get<3>(arr[idx]));
		S[c1] -= 1;
		S[c2] -= 1;
	}
	if (get<4>(arr[idx]) > 0.0)
	{
		S[c2] += 3;
		solve(idx + 1, r * get<4>(arr[idx]));
		S[c2] -= 3;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++)
	{
		cin >> order[i];
		R[order[i]] = 0; S[order[i]] = 0;
	}
	for (int i = 0; i < 6; i++)
	{
		cin >> A >> B >> W >> D >> L;
		arr[i] = make_tuple(A, B, W, D, L);
	}
	solve(0, 1.0);
	cout.precision(8);
	cout << fixed;
	for (int i = 0; i < 4; i++)
		cout << R[order[i]] << '\n';
}

// https://www.acmicpc.net/problem/15997