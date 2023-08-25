#include <iostream>
#include <vector>
using namespace std;

string IP, ans = "", tmp = "";
int cnt = 0, idx = -1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> IP;
	IP.push_back(':');
	for (int i = 0; i < IP.size(); i++)
	{
		if (IP[i] == ':')
		{
			if (tmp.size() == 0)
			{
				idx = cnt;
				continue;
			}
			while (tmp.size() < 4) tmp = '0' + tmp;
			ans += tmp;
			tmp = "";
			++cnt;
			if (i < IP.size() - 1) ans.push_back(':');
		}
		else
			tmp.push_back(IP[i]);
	}
	if (cnt < 8)
	{
		string a = "";
		for (int i = 0; i < idx * 5; ++i)
			a.push_back(ans[i]);
		for (int i = 0; i < 8 - cnt; ++i)
			a += "0000:";
		for (int i = idx * 5; i < ans.size(); ++i)
			a.push_back(ans[i]);
		if (a.size() > 39) a.pop_back();
		ans = a;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3107