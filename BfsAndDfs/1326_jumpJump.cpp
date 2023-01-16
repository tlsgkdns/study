#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int v[10001], N, A, B, S[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> S[i];
	cin >> A >> B;
	queue<int> q;
	q.push(A);
	v[A] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == B) break;
		for (int there = here - S[here]; there > 0; there -= S[here])
		{
			if (v[there] >= 0) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
		for (int there = here + S[here]; there <= N; there += S[here])
		{
			if (v[there] >= 0) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
	}
	cout << v[B] << '\n';
}

// https://www.acmicpc.net/problem/1326