#include <iostream>
#include <string>
#include <cctype>

using namespace std;
string L;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin.get();
	while (N--)
	{
		getline(cin, L);
		L[0] = toupper(L[0]);
		cout << L << '\n';
	}
}

// https://www.acmicpc.net/problem/4458