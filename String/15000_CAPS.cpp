#include <iostream>

using namespace std;

string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++) S[i] -= 32;
	cout << S << '\n';
}

// https://www.acmicpc.net/problem/15000