#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
int T, N, A[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int ans = 0;
		cin >> N;
		unordered_map<int, int> um;
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
			um[A[i]]++;
		}
		sort(A, A + N);
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
			{
				ans += (A[i] == A[j] && um[A[i]] > 3);
				ans += (um.find(2 * A[j] - A[i]) != um.end());
			}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/13423