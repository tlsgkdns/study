#include <iostream>
#include <algorithm>
using namespace std;

int pos[1000001], N, num, ans = 0, s = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		pos[num] = i;
	}
	for (int n = 2; n <= N; n++)
	{
		if (pos[n - 1] < pos[n]) s++;
		else
		{
			ans = max(ans, s);
			s = 1;
		}
	}
	cout << N - ans << '\n';
}

// https://www.acmicpc.net/problem/7570