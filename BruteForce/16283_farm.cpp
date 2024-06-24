#include <iostream>

using namespace std;

int A, B, N, W, ans1 = -1, ans2 = -1;
bool br = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> N >> W;
	for (int a = 1; a <= 1000 && !br; a++)
		for (int b = 1; b <= 1000 && !br; b++)
			if (a + b == N && a * A + b * B == W)
			{
				if (ans1 < 0)
				{
					ans1 = a;
					ans2 = b;
				}
				else
				{
					br = true;
					break;
				}
			}
	if (br || ans1 < 0) cout << -1 << '\n';
	else cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/16283