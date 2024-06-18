#include <iostream>
#include <stack>
using namespace std;

stack<char> S;
string str;
bool br = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'P')
		{
			if (!S.empty() && S.top() == 'A') S.pop();
			S.push('P');
		}
		else
		{
			if (S.size() < 2 || S.top() == 'A')
			{
				br = true;
				break;
			}
			else
			{
				S.pop();
				S.pop();
				S.push('A');
			}
		}
	}
	if (!br && S.size() == 1 && S.top() == 'P') cout << "PPAP\n";
	else cout << "NP\n";
}

// https://www.acmicpc.net/problem/16120