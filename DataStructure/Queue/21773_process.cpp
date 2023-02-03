#include <iostream>
#include <queue>

using namespace std;

int T, N, A, B, C;
int R[1000001], t[1000001];
struct cmp
{
	bool operator()(int a, int b)
	{
		if (R[a] == R[b]) return a > b;
		return R[a] < R[b];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, cmp> pq;
	cin >> T >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		R[A] = C;
		t[A] = B;
		pq.push(A);
	}
	int i = 0;
	while (!pq.empty() && i < T)
	{
		int now = pq.top();
		pq.pop();
		cout << now << '\n';
		++i;
		--R[now]; --t[now];
		if (t[now] <= 0) continue;
		pq.push(now);
	}
}

// https://www.acmicpc.net/problem/21773