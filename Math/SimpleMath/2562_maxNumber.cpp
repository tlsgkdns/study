#include <iostream>

int main()
{
	int ans = -1, n, cnt;
	for (int i = 0; i < 9; i++)
	{
		std::cin >> n;
		if (n > ans)
		{
			ans = n;
			cnt = i + 1;
		}
	}
	std::cout << ans << '\n' << cnt << '\n';
}
// https://www.acmicpc.net/problem/2562