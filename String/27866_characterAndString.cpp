#include <iostream>

using namespace std;

string S;
int i;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S; cin >> i;
	cout << S[i - 1] << '\n';
}

// https://www.acmicpc.net/problem/27866