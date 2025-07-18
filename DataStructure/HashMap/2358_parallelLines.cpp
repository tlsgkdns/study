#include <iostream>
#include <unordered_map>

using namespace std;

int X, Y, N, ans = 0;
unordered_map<int, int> p1, p2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		p1[X]++; p2[Y]++;
	}
	for (pair<int, int> p : p1)
		ans += (p.second >= 2);
	for (pair<int, int> p : p2)
		ans += (p.second >= 2);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2358