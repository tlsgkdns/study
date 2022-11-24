#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int N, M, num, ans = 0, r;
bool nums[10], password[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		nums[num] = true;
	}
	for (int n = 0; n < pow(10, N); n++)
	{
		int tmp = n, can = 0;
		memset(password, false, sizeof(password));
		for (int cnt = 0; cnt < N; cnt++)
		{
			r = tmp % 10;
			if (nums[r] && !password[r])
			{
				password[r] = true;
				can++;
			}
			tmp /= 10;
		}
		ans += (can == M);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13908