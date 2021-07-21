#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, cmd;
priority_queue<pair<int, int>> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd == 0)
		{
			if (!pq.empty())
			{
				ans.push_back(-pq.top().second);
				pq.pop();
			}
			else
				ans.push_back(0);
		}
		else
			pq.push(make_pair(-abs(cmd), -cmd));
	}
	for (int a : ans) cout << a << '\n';
}