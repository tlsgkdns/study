#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, int> um;
int N, tmp = 0;
string S, ans = "";


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> S;
		um[S]++;
		if (um[S] > tmp)
		{
			ans = S;
			tmp = um[S];
		}
		else if (um[S] == tmp && ans > S)
		{
			ans = S;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1302