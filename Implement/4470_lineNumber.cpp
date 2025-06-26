#include <iostream>
#include <string>

using namespace std;

string S;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	getline(cin, S);
	for (int i = 1; i <= N; i++)
	{
		getline(cin, S);
		cout << i << ". " << S << '\n';
	}
}

// https://www.acmicpc.net/problem/4470