#include <iostream>

using namespace std;

int H, W, N, M, ans = 1;

int main()
{
	cin >> H >> W >> N >> M;
	H--; W--; N++; M++;
	ans += (H / N);
	ans *= ((W / M) + 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/23971