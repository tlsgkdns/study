#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, string> um;
string S, P;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> P;
		um[S] = P;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> S;
		cout << um[S] << '\n';
	}
}

// https://www.acmicpc.net/problem/17219