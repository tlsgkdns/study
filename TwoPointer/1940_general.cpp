#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A[15001], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int l = 0, r = N - 1;
	while (l < r)
	{
		if (A[l] + A[r] > M) --r;
		else if (A[l] + A[r] == M)
		{
			++l; --r;
			++ans;
		}
		else
			++l;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1940