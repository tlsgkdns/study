#include <iostream>
#include <string>
#include <list>
using namespace std;

list<int> sub;
string s, tmp = "", st1 = "";
int n, f = 0;
int main()
{
	cin >> s;
	for (int i = s.length(); i >= 0; i--)
	{
		if (s[i] == '+')
		{
			f += stoi(tmp);
			tmp = "";
		}
		else if (s[i] == '-')
		{
			f += stoi(tmp);
			sub.push_front(f);
			f = 0;
			tmp = "";
		}
		else
			tmp = s[i] + tmp;
	}
	int ans = stoi(tmp) + f;
	for (int num : sub)
		ans -= num;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1541