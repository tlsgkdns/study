#include <iostream>
#include <cctype>
using namespace std;

string str, ans = "";
int java = 0;
bool U = false; char ch;
bool E = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	if (!isalpha(str.back()) || !isalpha(str.front()) || isupper(str.front()))
		E = true;
	for (int i = 0; i < str.size(); i++)
	{
		ch = str[i];
		if (ch == '_')
		{
			if (java == 0) java = -1;
			else if (java == 1)
			{
				E = true;
				break;
			}
		}
		else if (isupper(ch))
		{
			if (java == 0) java = 1;
			else if (java == -1)
			{
				E = true;
				break;
			}
		}
	}
	if (!E)
	{
		for (int i = 0; i < str.size(); i++)
		{
			ch = str[i];
			if (ch == '_')
			{
				if (U)
				{
					E = true;
					break;
				}
				U = true;
				continue;
			}
			if (isupper(ch))
			{
				ans.push_back('_');
				ch = tolower(ch);
			}
			if (U)
			{
				U = false;
				ch = toupper(ch);
			}
			ans.push_back(ch);
		}
	}
	if (E) ans = "Error!";
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3613