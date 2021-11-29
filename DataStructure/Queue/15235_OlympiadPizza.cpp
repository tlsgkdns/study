#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, num;
	queue<pair<int, int>> q;
	cin >> N;
	vector<int> ans(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		q.push({ num, i });
	}
	int time = 0;
	while (!q.empty())
	{
		int now = q.front().first;
		int per = q.front().second;
		q.pop();
		time++;
		now--;
		if (now == 0)
			ans[per] = time;
		else
			q.push({ now, per });
	}
	for (int a : ans) cout << a << " ";
	cout << '\n';
}
// https://www.acmicpc.net/problem/15235