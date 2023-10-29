#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;
int A, B, N, M, v[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> A >> B >> N >> M;
	v[N] = 0; q.push(N);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == M) break;
		if (here + 1 <= 100000 && v[here + 1] < 0)
		{
			v[here + 1] = v[here] + 1;
			q.push(here + 1);
		}
		if (here - 1 >= 0 && v[here - 1] < 0)
		{
			v[here - 1] = v[here] + 1;
			q.push(here - 1);
		}
		if (here * A <= 100000 && v[here * A] < 0)
		{
			v[here * A] = v[here] + 1;
			q.push(here * A);
		}
		if (here * B <= 100000 && v[here * B] < 0)
		{
			v[here * B] = v[here] + 1;
			q.push(here * B);
		}
		if (here + A <= 100000 && v[here + A] < 0)
		{
			v[here + A] = v[here] + 1;
			q.push(here + A);
		}
		if (here - A >= 0 && v[here - A] < 0)
		{
			v[here - A] = v[here] + 1;
			q.push(here - A);
		}
		if (here + B <= 100000 && v[here + B] < 0)
		{
			v[here + B] = v[here] + 1;
			q.push(here + B);
		}
		if (here - B >= 0 && v[here - B] < 0)
		{
			v[here - B] = v[here] + 1;
			q.push(here - B);
		}
	}
	cout << v[M] << '\n';
}

// https://www.acmicpc.net/problem/12761