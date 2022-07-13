#include <iostream>
using namespace std;

long long N, ans = 1;

int main()
{
	cin >> N;
	while (N >= ans)
	{
		N -= ans;
		ans++;
	}
	ans--;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1789