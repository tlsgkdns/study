#include <iostream>

using namespace std;

string N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == "0") break;
		int ans = N.size() + 1;
		for (int i = 0; i < N.size(); i++)
			if (N[i] == '1') ans += 2;
			else if (N[i] == '0') ans += 4;
			else ans += 3;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1284