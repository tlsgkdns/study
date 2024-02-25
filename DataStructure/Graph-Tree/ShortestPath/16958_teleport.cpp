#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> teleport;
int N, T, S, X[1001], Y[1001], M, A, B, D[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	for (int i = 1; i <= N; i++) D[i] = 1000000007;
	for (int i = 1; i <= N; i++)
	{
		cin >> S >> X[i] >> Y[i];
		if (S == 1) teleport.push_back({ X[i], Y[i] });
	}
	for (int i = 1; i <= N; i++)
		for (int idx = 0; idx < teleport.size(); idx++)
			D[i] = min(D[i], abs(teleport[idx].first - X[i]) + abs(teleport[idx].second - Y[i]));
	cin >> M;
	while (M--)
	{
		cin >> A >> B;
		cout << min(abs(X[A] - X[B]) + abs(Y[A] - Y[B]), D[A] + T + D[B]) << '\n';
	}
}

// https://www.acmicpc.net/problem/16958