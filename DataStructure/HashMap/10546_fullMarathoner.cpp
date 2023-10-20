#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> um;
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
		um[S]++;
	}
	for (int i = 0; i < N - 1; i++)
	{
		cin >> S;
		um[S]--;
	}
	for (auto iter = um.begin(); iter != um.end(); iter++)
		if ((*iter).second > 0)
		{
			cout << (*iter).first << '\n';
			break;
		}
}

// https://www.acmicpc.net/problem/10546