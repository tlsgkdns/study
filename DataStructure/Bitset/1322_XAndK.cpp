#include <iostream>

using namespace std;
using ll = long long;
ll X, K, ans = 0, idx1 = 0, idx2 = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X >> K;
	while ((1LL << idx1) <= K)
	{
		if ((X & (1LL << idx2)) == 0)
		{
			ans = ans | ((ll)((K & (1LL << idx1)) > 0) << idx2);
			++idx1;
		}
		++idx2;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1322