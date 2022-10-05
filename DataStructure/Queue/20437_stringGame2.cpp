#include <iostream>
#include <queue>
using namespace std;

string W;
int T, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> W;
		cin >> K;
		queue<int> q[26];
		int a1 = 10001, a2 = -1;
		if (K > 1)
		{
			for (int i = 0; i < (int)W.size(); i++)
			{
				if ((int)q[W[i] - 'a'].size() == K - 1)
				{
					a1 = min(a1, i - q[W[i] - 'a'].front() + 1);
					a2 = max(a2, i - q[W[i] - 'a'].front() + 1);
					q[W[i] - 'a'].pop();
				}
				q[W[i] - 'a'].push(i);
			}
		}
		else
		{
			a1 = 1;  a2 = 1;
		}
		if (a2 == -1) cout << -1 << '\n';
		else cout << a1 << " " << a2 << '\n';
	}
}

// https://www.acmicpc.net/problem/20437