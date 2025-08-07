#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int N, K, ans = 0;

bool chk(int num)
{
	return ((num % 10) == K) || ((num / 10) == K);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int h = 0; h <= N; h++)
		for (int m = 0; m < 60; m++)
			for (int s = 0; s < 60; s++)
				ans += (chk(h) || chk(m) || chk(s));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18312