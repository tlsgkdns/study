#include <iostream>

using namespace std;
int T;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> S;
		cout << S[0] << S.back() << '\n';
	}
}

// https://www.acmicpc.net/problem/9086