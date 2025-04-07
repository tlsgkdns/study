#include <iostream>
#include <algorithm>

using namespace std;

int A, B, ans = 0, S = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
	{
		cin >> A >> B;
		S -= A;
		S += B;
		ans = max(ans, S);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2460