#include <iostream>
#include <algorithm>
using namespace std;

string S, T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S >> T;
	while (T.size() > S.size())
	{
		if (T.back() == 'A') T = string(T.begin(), T.end() - 1);
		else if (T.back() == 'B')
		{
			T = string(T.begin(), T.end() - 1);
			reverse(T.begin(), T.end());
		}
		else
			break;
	}
	cout << (S == T) << '\n';
}

// https://www.acmicpc.net/problem/12904