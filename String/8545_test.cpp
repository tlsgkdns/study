#include <iostream>
#include <algorithm>

using namespace std;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> S;
	reverse(S.begin(), S.end());
	cout << S << '\n';
}

// https://www.acmicpc.net/problem/8545