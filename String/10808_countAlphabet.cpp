#include <iostream>

using namespace std;
string S;
int alp[26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++) ++alp[S[i] - 'a'];
	for (int i = 0; i < 26; i++) cout << alp[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/10808