#include <iostream>

using namespace std;

int A, B, ans = 0;
int D[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
string S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++) ans += D[S[i] - 'A'] + 1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5622