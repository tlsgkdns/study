#include <iostream>
#include <deque>
using namespace std;
int N, ans[1001], A, num[1001];
deque<int> dq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		dq.push_back(i);
	}
	for (int i = 0; i < N; i++)
	{
		ans[i] = dq.front();
		A = num[ans[i]];
		dq.pop_front();
		if (dq.empty()) break;
		if (A > 0)
		{
			A--;
			while (A > 0)
			{
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				A--;
			}
		}
		else
		{
			while (A < 0)
			{
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				A++;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2346