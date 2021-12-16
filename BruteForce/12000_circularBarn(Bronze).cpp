#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, ans = 1000000000;
vector<int> barn;

int getClockwiseIdx(int idx)
{
	return (idx + 1) % N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	barn.resize(N);
	for (int i = 0; i < N; i++)
		cin >> barn[i];
	for (int start = 0; start < N; start++)
	{
		int idx = start, step = 0, cnt = 0;
		do
		{
			step += barn[idx] * cnt;
			cnt++;
			idx = getClockwiseIdx(idx);
		} while (idx != start);
		ans = min(ans, step);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12000