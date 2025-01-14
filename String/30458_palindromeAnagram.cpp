#include <iostream>

using namespace std;
using ll = long long;

int N;
string S;
int a[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> S;
	for (int i = 0; i < (N / 2); i++) a[S[i] - 'a']++;
	for (int i = (N / 2) + (N % 2); i < N; i++) a[S[i] - 'a']++;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] % 2 == 1)
		{
			cout << "No\n";
			break;
		}
		if (i == 25)
		{
			cout << "Yes\n";
		}
	}
}

// https://www.acmicpc.net/problem/30458