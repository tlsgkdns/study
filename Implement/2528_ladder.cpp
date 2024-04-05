#include <iostream>

using namespace std;

int N, L, l[3001], d[3001], now = 0;

pair<int, int> getPos(int t, int idx)
{
	if (L == l[idx]) return { 0, l[idx] };
	int dir = d[idx];
	if ((t / (L - l[idx])) % 2) dir = !dir;
	int m = t % (L - l[idx]);
	if (dir) return { L - l[idx] - m, L - m };
	else return { m, l[idx] + m };
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> l[i] >> d[i];
	int t = 0;
	while (now < N - 1)
	{
		pair<int, int> pos1 = getPos(t, now);
		pair<int, int> pos2 = getPos(t, now + 1);
		if (pos1.second < pos2.first || pos2.second < pos1.first) ++t;
		else ++now;
	}
	cout << t << '\n';
}

// https://www.acmicpc.net/problem/2528