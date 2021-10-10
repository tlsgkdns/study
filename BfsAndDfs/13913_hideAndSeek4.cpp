#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int m = 100001;
int N, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	queue<int> q;
	vector<int> ans;
	q.push(N);
	vector<int> v(m, -1);
	v[N] = N;
	while (!q.empty())
	{
		int n = q.front();
		if (n == K)
		{
			while (n != N)
			{
				ans.push_back(n);
				n = v[n];
			}
			ans.push_back(n);
			break;
		}
		if (n < K)
		{
			if (n + 1 <= m && v[n + 1] == -1)
			{
				v[n + 1] = n;
				q.push(n + 1);
			}
			if (2 * n <= m && v[2 * n] == -1)
			{
				v[2 * n] = n;
				q.push(2 * n);
			}
		}
		if (n - 1 >= 0 && v[n - 1] == -1)
		{
			v[n - 1] = n;
			q.push(n - 1);
		}
		q.pop();
	}
	cout << ans.size() - 1 << '\n';
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
	cout << '\n';
}
// https://www.acmicpc.net/problem/13913