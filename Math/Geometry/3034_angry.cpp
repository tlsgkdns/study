#include <iostream>
using namespace std;

int N, W, H, M, L = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> W >> H;
	L = W * W + H * H;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		if (M * M <= L)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
}

// https://www.acmicpc.net/problem/3034