#include <iostream>
#include <deque>
using namespace std;

int N, K, ans = 0;
string bench;

bool toBool(char c)
{
	if (c == 'H') return true;
	else return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> bench;
	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		bool b = toBool(bench[i]);
		if (!dq.empty() && i - dq.front() > K)
			dq.pop_front();
		if (dq.empty())
		{
			dq.push_back(i);
			continue;
		}
		if (toBool(bench[dq.front()]) == b)
		{
			dq.push_back(i);
		}
		else
		{
			dq.pop_front();
			ans++;
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/19941