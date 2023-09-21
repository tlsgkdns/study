#include <iostream>
#include <algorithm>
using namespace std;

int A[100001], N, M, ans = 2000000003;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int l = 0, r = 1;
	while (r < N)
	{
		if (A[r] - A[l] < M) ++r;
		else
		{
			ans = min(ans, A[r] - A[l]);
			++l;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2230