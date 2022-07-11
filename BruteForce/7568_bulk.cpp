#include <iostream>

using namespace std;

int N;
int W[51], H[51];
int ans[51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> W[i] >> H[i];
	for (int i = 0; i < N; i++)
	{
		int B = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (W[j] > W[i] && H[j] > H[i]) B++;
		}
		ans[i] = B + 1;
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << '\n';
}

//https://www.acmicpc.net/problem/7568