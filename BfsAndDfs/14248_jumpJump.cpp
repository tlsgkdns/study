#include <iostream>
#include <queue>

using namespace std;
int ans = 1, N, A[100001], S;
bool v[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> S;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		int there = here - A[here];
		if (there >= 1 && !v[there])
		{
			v[there] = true;
			++ans;
			q.push(there);
		}
		there = here + A[here];
		if (there <= N && !v[there])
		{
			v[there] = true;
			++ans;
			q.push(there);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14248