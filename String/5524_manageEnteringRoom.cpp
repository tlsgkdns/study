#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;
int N;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		transform(S.begin(), S.end(), S.begin(), [](char c) {return tolower(c); });
		cout << S << '\n';
	}
}

// https://www.acmicpc.net/problem/5524