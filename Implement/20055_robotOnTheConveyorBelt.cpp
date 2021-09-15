#include <iostream>
#include <vector>
using namespace std;

int N, K, z = 0;
vector<int> belt;
vector<bool> robot;
void rotate()
{
	vector<int> tmp1(2 * N, -1);
	vector<bool> tmp2(N, false);
	for (int i = 1; i < 2 * N; i++)
		tmp1[i] = belt[i - 1];
	for (int r = 1; r < N; r++)
		tmp2[r] = robot[r - 1];
	if (tmp2.back()) tmp2[N - 1] = false;
	tmp1[0] = belt.back();
	tmp2[0] = robot.back();
	belt = tmp1;
	robot = tmp2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	belt.resize(2 * N); robot.resize(2 * N, false);
	for (int i = 0; i < 2 * N; i++)
	{
		cin >> belt[i];
		if (belt[i] == 0) z++;
	}
	int ans = 0;
	do
	{
		rotate();
		for (int r = N - 2; r >= 0; r--)
		{
			if (!robot[r]) continue;
			int next = ((r + 1) % N);
			if (belt[next] == 0 || robot[next]) continue;
			belt[next]--; if (belt[next] == 0) z++;
			robot[r] = false;
			if (next != N - 1)	robot[next] = true;
		}
		if (belt[0] != 0)
		{
			belt[0]--;
			if (belt[0] == 0) z++;
			robot[0] = true;
		}
		ans++;
	} while (z < K);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/20055