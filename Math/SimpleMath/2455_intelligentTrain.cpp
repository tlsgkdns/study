#include <iostream>

using namespace std;

int A, B, ans, C = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++)
	{
		cin >> A >> B;
		C -= A;
		C += B;
		ans = (ans < C) ? C : ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2455