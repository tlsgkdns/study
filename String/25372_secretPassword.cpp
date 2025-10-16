#include <iostream>

using namespace std;

int N;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> S;
		if (S.size() >= 6 && S.size() <= 9) cout << "yes\n";
		else cout << "no\n";
	}
}

// https://www.acmicpc.net/problem/25372