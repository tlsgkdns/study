#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> arr;
int W, N = 0, A[5001], dp[800000], P[800000];
bool ans = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, 0, sizeof(dp));
	cin >> W >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (A[i] + A[j] < W)
			{
				arr.push_back(A[i] + A[j]);
				++dp[arr.back()];
				P[arr.back()] = A[j];
			}
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (dp[W - arr[i]] <= 0) continue;
		if (dp[W - arr[i]] >= 2)
		{
			ans = true;
			break;
		}
		int a = P[arr[i]], b = arr[i] - P[arr[i]], c = P[W - arr[i]], d = (W - arr[i]) - P[W - arr[i]];
		if (a == c || a == d || b == c || b == d) continue;
		ans = true;
		break;
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/16287