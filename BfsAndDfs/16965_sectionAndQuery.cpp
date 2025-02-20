#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, C, A, B, x[101], y[101], idx = 1;
bool v[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> C;
		if (C == 1)
		{
			cin >> x[idx] >> y[idx];
			idx++;
		}
		else
		{
			cin >> A >> B;
			int ans = 0;
			memset(v, false, sizeof(v));
			v[A] = true;
			queue<int> q;
			q.push(A);
			while (!q.empty())
			{
				int here = q.front();
				q.pop();
				if (here == B)
				{
					ans = 1;
					break;
				}
				for (int i = 1; i < idx; i++)
				{
					if (!v[i] && ((x[i] < x[here] && x[here] < y[i]) || (x[i] < y[here] && y[here] < y[i])))
					{
						v[i] = true;
						q.push(i);
					}
				}
			}
			cout << ans << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/16965