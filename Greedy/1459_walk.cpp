#include <iostream>
#include <algorithm>
using namespace std;

long long X, Y, W, S, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X >> Y >> W >> S;
	if (2 * W <= S)
		ans = (X + Y) * W;
	else
	{
		if (X > Y) swap(X, Y);
		if (W > S) ans = S * X + S * (((Y - X) / 2) * 2) + (W * ((Y - X) % 2));
		else ans = S * X + (Y - X) * W;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1459