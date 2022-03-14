#include <iostream>

using namespace std;
int M, A, B, C;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	int ans = 1;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		int rot = (ans / A) * B;
		if (C == 1) rot = -rot;
		ans = rot;
	}
	if (ans < 0) cout << 1 << " " << -ans;
	else cout << 0 << " " << ans;
}

// https://www.acmicpc.net/problem/10834