#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
string S;
int solve(char t)
{
	int c = 0;
	bool f = false;
	for (int i = 0; i < N; i++)
	{
		if (S[i] == t)
		{
			if (!f)
			{
				++c;
				f = true;
			}
		}
		else
		{
			f = false;
		}
	}
	return c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> S;
	int c1 = solve('R'), c2 = solve('B');
	cout << min(c1, c2) + 1 << '\n';
}

// https://www.acmicpc.net/problem/20365