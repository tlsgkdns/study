#include <iostream>
#include <cmath>

using namespace std;

string S;
long long ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		ans += (S[i] - 'A' + 1) * pow(26, (S.size() - i - 1));
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16495