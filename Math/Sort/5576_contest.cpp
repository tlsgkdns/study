#include <iostream>
#include <algorithm>

using namespace std;

int W[10], K[10];
int a1 = 0, a2 = 0;
long long ans = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++) cin >> W[i];
	for (int i = 0; i < 10; i++) cin >> K[i];
	sort(W, W + 10); sort(K, K + 10);
	for (int i = 7; i <= 9; i++)
	{
		a1 += W[i];
		a2 += K[i];
	}
	cout << a1 << " " << a2 << '\n';
}

// https://www.acmicpc.net/problem/5576