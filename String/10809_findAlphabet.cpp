#include <iostream>
#include <cstring>

int ans[26];
std::string str;
int main()
{
	memset(ans, -1, sizeof(ans));
	std::cin >> str;
	for (int i = 0; i < (int)str.size(); i++)
		if (ans[str[i] - 'a'] == -1)
			ans[str[i] - 'a'] = i;
	for (int i = 0; i < 26; i++) std::cout << ans[i] << " ";
	std::cout << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/10809