#include <iostream>
#include <algorithm>
using namespace std;

int N, M, I, J, K, ans[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	while (M--)
	{
		cin >> I >> J >> K;
		for (int i = I; i <= J; i++)
			ans[i] = K;
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/10810