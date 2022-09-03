#include <iostream>
using namespace std;
int N, M, prv = -1, cur, A, B;
int arr[100001], psum[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> cur;
		if (prv < 0)
			psum[i] = cur;
		else
			psum[i] = prv + cur;
		prv = psum[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		cout << psum[B] - psum[A - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/11659