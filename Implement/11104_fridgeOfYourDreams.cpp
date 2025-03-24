#include <iostream>

using namespace std;

int N;
string B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> B;
		int ans = 0;
		for (int i = B.size() - 1, b = 1; i >= 0; i--, b *= 2)
			if (B[i] == '1')
				ans += b;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/11104