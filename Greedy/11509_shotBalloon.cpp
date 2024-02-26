#include <iostream>
#include <algorithm>
using namespace std;

int N, B[1000001], ans = 0;
int v[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < N; i++)
	{
		if (v[B[i]] > 0)
		{
			--v[B[i]];
			++v[B[i] - 1];
		}
		else
		{
			++v[B[i] - 1];
			++ans;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11509