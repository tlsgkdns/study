#include <iostream>

using namespace std;


int main(void)
{
	string cam = "CAMBRIDGE";
	string st, ans;
	bool flag = false;
	cin >> st;

	for (char s : st)
	{
		for (char c : cam)
		{
			if (c == s)
			{
				flag = true;
				break;
			}
		}
		if (!flag) ans.push_back(s);
		flag = false;
	}

	cout << ans << endl;
}

// https://www.acmicpc.net/problem/2789