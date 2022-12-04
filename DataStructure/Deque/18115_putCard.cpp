#include <iostream>
#include <deque>
using namespace std;

int arr[1000001], N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	deque<int> dq;
	for (int i = N; i > 0; i--)
	{
		if (arr[i] == 1)
			dq.push_front(N - i + 1);
		else if (arr[i] == 2)
		{
			int tmp = dq.front();
			dq.pop_front();
			dq.push_front(N - i + 1);
			dq.push_front(tmp);
		}
		else
			dq.push_back(N - i + 1);
	}
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/18115