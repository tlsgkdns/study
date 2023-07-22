#include <iostream>
#include <queue>
using namespace std;

int N, A, B, R = 1, ans = -1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); cout.tie(NULL);
	cin >> N >> A >> B;
	queue<int> q;
	for (int i = 1; i <= N; i++) q.push(i);
	while (q.size() > 1 && ans < 0)
	{
		int s = (int)q.size();
		for (int i = 0; i < s; i += 2)
		{
			if (s - i == 1)
			{
				q.push(q.front());
				q.pop();
				break;
			}
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			if ((a == A && b == B) || (a == B && b == A))
			{
				ans = R;
				break;
			}
			if (b == B || b == A) q.push(b);
			else q.push(a);
		}
		++R;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1057