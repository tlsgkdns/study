#include <iostream>

using namespace std;

int T, H, W, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;
		int X = (N - 1) / H, Y = (N - 1) % H; ++X; ++Y;
		if ((X / 10) > 0) cout << Y << X << '\n';
		else cout << Y << 0 << X << '\n';
	}
}

// https://www.acmicpc.net/problem/10250