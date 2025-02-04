#include <iostream>
#include <algorithm>

using namespace std;

string N;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int idx = 0; idx < N.size(); idx++)
	{
		int n = (N[idx] - '0'), s = 1;
		for (int i = 0; i < 5; i++)
			s *= n;
		ans += s;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/23037