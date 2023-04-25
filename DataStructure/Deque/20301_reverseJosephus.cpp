#include <iostream>
#include <deque>
using namespace std;

int N, M, K, cnt = 0, r = 0;
bool rev = false;
deque<int> dq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	while (!dq.empty())
	{
		++cnt;
		if (rev)
		{
			int now = dq.back();
			dq.pop_back();
			if (cnt % K == 0)
			{
				cout << now << '\n';
				++r;
				if (r % M == 0) rev = !rev;
			}
			else dq.push_front(now);
		}
		else
		{
			int now = dq.front();
			dq.pop_front();
			if (cnt % K == 0)
			{
				cout << now << '\n';
				++r;
				if (r % M == 0) rev = !rev;
			}
			else dq.push_back(now);
		}
	}
}

// https://www.acmicpc.net/problem/20301