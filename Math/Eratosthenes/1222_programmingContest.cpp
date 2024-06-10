#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
ll D[2000001], ans = 0;
int N, P;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P;
		++D[P];
	}
	for (int i = 1; i <= 2000000; i++)
	{
		ll cnt = 0;
		for (int j = i; j <= 2000000; j += i) cnt += D[j];
		if (cnt > 1) ans = max(cnt * i, ans);
	}
	cout << ans << '\n';
}
