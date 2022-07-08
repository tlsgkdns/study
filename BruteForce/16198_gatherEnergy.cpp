#include <iostream>
#include <algorithm>
using namespace std;

int N;
int W[11];
bool v[11];

int solve(int d)
{
	if (d == 0) return 0;
	int ret = 0;
	for (int i = 1; i < N - 1; i++)
	{
		if (v[i]) continue;
		int l = i, r = i;
		v[i] = true;
		while (v[l]) l--; while (v[r]) r++;
		ret = max(ret, solve(d - 1) + W[l] * W[r]);
		v[i] = false;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> W[i];
	cout << solve(N - 2) << '\n';
}


// https://www.acmicpc.net/problem/16198