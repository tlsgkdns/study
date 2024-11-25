#include <iostream>

using namespace std;

int N, A[5001], ans = 0;
bool ch[400001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
			ch[A[i - 1] + A[j] + 200000] = true;
		for (int j = i - 1; j >= 0; j--)
			if (ch[A[i] - A[j] + 200000])
			{
				++ans;
				break;
			}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5624