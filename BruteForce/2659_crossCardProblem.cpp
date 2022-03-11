#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string in;
char c;
int cnt = 1;
int order[10000];
string getNext(string str)
{
	string ret(str.begin() + 1, str.end());
	ret.push_back(str[0]);
	return ret;
}
bool includeZero(int num)
{
	while (num != 0)
	{
		if (num % 10 == 0) return true;
		num /= 10;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(order, -1, sizeof(order));
	for (int num = 1111; num <= 9999; num++)
	{
		if (includeZero(num)) continue;
		string str = to_string(num);
		bool done = false;
		for (int d = 0; d < 4; d++)
		{
			str = getNext(str);
			int idx = stoi(str);
			if (order[idx] != -1) continue;
			done = true;
			order[idx] = cnt;
		}
		if (done) cnt++;
	}
	int ans = order[9999];
	for (int i = 0; i < 4; i++)
	{
		cin >> c;
		in.push_back(c);
	}
	for (int i = 0; i < 4; i++)
	{
		in = getNext(in);
		ans = min(ans, order[stoi(in)]);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2659