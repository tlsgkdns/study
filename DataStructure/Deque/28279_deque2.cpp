#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int C, X, N;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> C;
		switch (C)
		{
		case 1:
		{
			cin >> X;
			dq.push_front(X);
			break;
		}
		case 2:
		{
			cin >> X;
			dq.push_back(X);
			break;
		}
		case 3:
		{
			if (dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			break;
		}
		case 4:
		{
			if (dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			break;
		}
		case 5:
		{
			cout << dq.size() << '\n';
			break;
		}
		case 6:
		{
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		}
		case 7:
		{
			if (dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';
			}
			break;
		}
		default:
		{
			if (dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';
			}
			break;
		}

		break;
		}
	}
}

// https://www.acmicpc.net/problem/28279