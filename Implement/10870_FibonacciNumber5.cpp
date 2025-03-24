#include <iostream>

using namespace std;

int N, a1 = 0, a2 = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	if (N == 0) cout << 0 << '\n';
	else
	{
		for (int i = 2; i <= N; i++)
		{
			int now = a1 + a2;
			a1 = a2;
			a2 = now;
		}
		cout << a2 << '\n';
	}
}


// https://www.acmicpc.net/problem/10870