#include <iostream>
#include <cmath>
using namespace std;

string W[2];
int alp[2][26], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> W[0];
	cin >> W[1];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < W[i].size(); j++)
			alp[i][W[i][j] - 'a']++;
	for (int i = 0; i < 26; i++)
		ans += abs(alp[0][i] - alp[1][i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1919