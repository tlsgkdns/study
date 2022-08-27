#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string X, Y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X >> Y;
	reverse(X.begin(), X.end());
	reverse(Y.begin(), Y.end());
	int x = stoi(X), y = stoi(Y);
	x += y;
	string a = to_string(x);
	reverse(a.begin(), a.end());
	int idx = 0;
	while (a[idx] == '0') idx++;
	string ans(a.begin() + idx, a.end());
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1357