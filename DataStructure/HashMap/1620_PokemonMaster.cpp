#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, int> d1;
unordered_map<int, string> d2;
int N, M;
string S;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> S;
		d1.insert({ S, i });
		d2.insert({ i, S });
	}
	for (int i = 0; i < M; i++)
	{
		cin >> S;
		try {
			int idx = stoi(S);
			cout << d2[idx] << '\n';
		}
		catch (exception& e)
		{
			cout << d1[S] << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/1620