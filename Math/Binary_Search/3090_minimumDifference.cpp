#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
int N, T;
int A[MAX_N], tmp[MAX_N], ans[MAX_N];
bool poss(int sub)
{
	memcpy(tmp, A, sizeof(tmp));
	long long cnt = 0;
	for (int i = 0; i < N - 1; i++)
	{
		int s = tmp[i + 1] - tmp[i];
		if (sub >= s) continue;
		cnt += (s - sub);
		tmp[i + 1] = tmp[i] + sub;
	}
	for (int i = N - 1; i > 0; i--)
	{
		int s = tmp[i - 1] - tmp[i];
		if (sub >= s) continue;
		cnt += (s - sub);
		tmp[i - 1] = tmp[i] + sub;
	}
	return cnt <= T;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	int l = -1, r = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		r = max(A[i], r);
	}
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (poss(mid))
		{
			memcpy(ans, tmp, sizeof(ans));
			r = mid;
		}
		else l = mid;
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/3090