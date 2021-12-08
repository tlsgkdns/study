#include <iostream>
#include <vector>
using namespace std;

int N, R, n;
vector<bool> dive;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> R;
	dive.resize(N + 1, false);
	for (int i = 0; i < R; i++)
	{
		cin >> n;
		dive[n] = true;
	}
	if (N == R) cout << "*";
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!dive[i])
				cout << i << " ";
		}
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/13627