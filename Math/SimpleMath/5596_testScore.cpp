#include <iostream>
#include <algorithm>
using namespace std;

int S, ans[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> S;
			ans[i] += S;
		}
	cout << max(ans[0], ans[1]) << '\n';
}

// https://www.acmicpc.net/problem/5596