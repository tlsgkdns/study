#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<char, int> um = { {'-', 0}, {'\\', 1}, {'(', 2}, {'@', 3}, {'?', 4}, {'>', 5}, {'&', 6}, {'%', 7}, {'/', -1} };
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> str;
		if (str == "#") break;
		long long ans = 0;
		for (int i = 0; i < str.size(); i++)
			ans += pow(8, str.size() - i - 1) * um[str[i]];
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1864