#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int K, A, B, C;
double ans = 0, D[101], s = 0, cost = 0;
int main()
{
	cin >> K;
	cin >> A >> B;
	cin >> C;
	for (int i = 0; i < K; i++) cin >> D[i];
	sort(D, D + K);
	s += C; cost += A; ans = ((double)s / cost);
	for (int i = K - 1; i >= 0; i--)
	{
		s += D[i];
		cost += B;
		ans = max(s / cost, ans);
	}
	cout << floor(ans) << '\n';
}

// https://www.acmicpc.net/problem/5545