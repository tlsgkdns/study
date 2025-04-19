#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int N;
string S[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	for (int i = S[0].size() - 1; i >= 0; i--)
	{
		set<string> s;
		bool f = true;
		for (int idx = 0; idx < N; idx++)
		{
			string str(S[idx].begin() + i, S[idx].end());
			if (s.find(str) != s.end())
			{
				f = false;
				break;
			}
			s.insert(str);
		}
		if (f)
		{
			cout << S[0].size() - i << '\n';
			break;
		}
	}
}

// https://www.acmicpc.net/problem/1235