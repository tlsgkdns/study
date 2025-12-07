#include <iostream>
#include <algorithm>
using namespace std;


int N, K, S[51];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> K;
		for (int idx = 0; idx < K; idx++) cin >> S[idx];
		sort(S, S + K);
		int a = 0;
		for (int idx = 0; idx < K - 1; idx++) a = max(S[idx + 1] - S[idx], a);
		cout << "Class " << i << '\n';
		cout << "Max " << S[K - 1] << ", " << "Min " << S[0] << ", Largest gap " << a << '\n';
	}
}

// https://www.acmicpc.net/problem/5800