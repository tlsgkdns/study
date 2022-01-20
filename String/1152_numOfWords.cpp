#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	int ans = 0;
	getline(cin, str);
	bool blank = true;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') blank = true;
		else if (blank)
		{
			blank = false;
			ans++;
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1152