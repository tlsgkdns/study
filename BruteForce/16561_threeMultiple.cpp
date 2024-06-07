#include <iostream>

using namespace std;
int N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n1 = 3; n1 <= N; n1 += 3)
		for (int n2 = 3; n2 <= N - n1; n2 += 3)
			ans += ((N - n1 - n2 > 0) && ((N - n1 - n2) % 3) == 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16561