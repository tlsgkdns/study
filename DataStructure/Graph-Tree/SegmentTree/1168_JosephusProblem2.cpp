#include <iostream>
using namespace std;

const int MAX = 100001;
int T[MAX * 4], N, K, now;

void init(int s, int e, int node)
{
	if (s == e)
	{
		T[node] = 1;
		return;
	}
	int m = (s + e) / 2;
	init(s, m, node * 2);
	init(m + 1, e, node * 2 + 1);
	T[node] = T[node * 2] + T[node * 2 + 1];
}

int query(int s, int e, int target, int node)
{
	T[node] -= 1;
	if (s == e) return s;
	int m = (s + e) / 2;
	if (T[node * 2] >= target) return query(s, m, target, node * 2);
	return query(m + 1, e, target - T[node * 2], node * 2 + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	now = K;
	init(1, N, 1);
	cout << "<";
	for (int i = 0; i < N; i++)
	{
		cout << query(1, N, now, 1);
		if (i == N - 1)
			cout << ">\n";
		else
		{
			cout << ", ";
			now += K - 1;
			now = (now - 1) % T[1] + 1;
		}
	}
}

// https://www.acmicpc.net/problem/1168