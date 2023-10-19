#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> C;
int N, X, R;
bool v[200001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> R;
		C.push_back({ X - R, i });
		C.push_back({ X + R, i });
	}
	sort(C.begin(), C.end());
	bool f = false;
	for (int i = 1; i < C.size(); i++)
		if (C[i].first == C[i - 1].first)
		{
			f = true;
			break;
		}
	if (!f)
	{
		stack<int> S;
		for (int i = 0; i < C.size(); i++)
			if (!v[C[i].second])
			{
				v[C[i].second] = true;
				S.push(C[i].second);
			}
			else
			{
				if (S.top() == C[i].second)
					S.pop();
				else
				{
					f = true;
					break;
				}
			}
	}
	if (f) cout << "NO\n";
	else cout << "YES\n";
}

// https://www.acmicpc.net/problem/22942