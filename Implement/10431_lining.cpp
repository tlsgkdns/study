#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int P, T, H;
vector<pair<int, int>> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P;
	for (int i = 0; i < P; i++)
	{
		deque<int> dq;
		int a = 0;
		cin >> T;
		for (int j = 0; j < 20; j++)
		{
			cin >> H;
			if (dq.empty() || dq.back() < H) dq.push_back(H);
			else
			{
				vector<int> tmp;
				while (!dq.empty() && dq.front() < H)
				{
					tmp.push_back(dq.front());
					dq.pop_front();
				}
				a += (int)dq.size();
				dq.push_front(H);
				while (!tmp.empty())
				{
					dq.push_front(tmp.back());
					tmp.pop_back();
				}
			}
		}
		ans.push_back({ T, a });
	}
	for (int i = 0; i < P; i++)
		cout << ans[i].first << " " << ans[i].second << '\n';
}

// https://www.acmicpc.net/problem/10431