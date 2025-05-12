#include <iostream>
#include <set>

using namespace std;
string W;
int s = 0;
string ans = "It is a prime word.";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> W;
	for (int i = 0; i < W.size(); i++)
	{
		if (W[i] >= 'a') s += (W[i] - 'a') + 1;
		else s += (W[i] - 'A') + 27;
	}
	for (int i = 2; i * i <= s; i++)
		if (s % i == 0)
		{
			ans = "It is not a prime word.";
			break;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2153