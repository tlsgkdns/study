#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10001;
int N, K, D, A[MAX], B[MAX], C[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> D;
	int l = 0, r = N;
	for (int i = 0; i < K; i++) cin >> A[i] >> B[i] >> C[i];
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		long long s = 0;
		for (int i = 0; i < K; i++)
		{
			if (m < A[i]) continue;
			s += (min(B[i], m) - A[i]) / C[i] + 1;
		}
		if (s < D) l = m;
		else r = m;
	}
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/15732