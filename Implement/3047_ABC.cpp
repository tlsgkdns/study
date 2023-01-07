#include <iostream>
#include <algorithm>
using namespace std;
string S;
int a[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> a[i];
	cin >> S; sort(a, a + 3);
	for (int i = 0; i < 3; i++) cout << a[S[i] - 'A'] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/3047