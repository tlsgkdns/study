#include <iostream>
using namespace std;

int N, M, H[100002], A, B, K, S = 0, O[100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> H[i];
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> K;
		O[A] += K;
		O[B + 1] += -K;
	}
	for (int i = 1; i <= N; i++)
	{
		S = S + O[i];
		cout << H[i] + S << " ";
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/19951