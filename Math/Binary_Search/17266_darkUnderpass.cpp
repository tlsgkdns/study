#include <iostream>

using namespace std;

int N, M, X[100001];
bool solve(int h)
{
	int L = 0;
	for (int i = 0; i < M; i++)
	{
		if (L < X[i] - h) return false;
		L = X[i] + h;
	}
	return L >= N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) cin >> X[i];
	int l = 0, r = N;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m)) r = m;
		else l = m;
	}
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/17266