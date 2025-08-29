#include <iostream>
using namespace std;
int N, alp[26];
string S;
bool p = true;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		alp[S[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (alp[i] >= 5)
		{
			p = false;
			cout << (char)(i + 'a');
		}
	}
	if (p) cout << "PREDAJA\n";
}


// https://www.acmicpc.net/problem/1159