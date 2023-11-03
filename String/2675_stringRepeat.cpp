#include <iostream>

using namespace std;

int T, R;
string S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> R >> S;
		for (int i = 0; i < S.size(); i++)
		{
			for (int c = 0; c < R; c++) cout << S[i];
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2675