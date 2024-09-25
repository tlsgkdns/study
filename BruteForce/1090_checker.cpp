#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, X[51], Y[51], ans[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i] >> Y[i];
		ans[i] = 1000000007;
	}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			vector<int> C;
			for (int i = 0; i < N; i++)
				C.push_back(abs(X[x] - X[i]) + abs(Y[y] - Y[i]));
			sort(C.begin(), C.end());
			int s = 0;
			for (int i = 0; i < C.size(); i++)
			{
				s += C[i];
				ans[i] = min(s, ans[i]);
			}
		}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1090