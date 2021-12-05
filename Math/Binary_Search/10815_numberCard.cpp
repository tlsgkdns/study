#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, num, l, r;
vector<int> card, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; card.resize(N);
	for (int i = 0; i < N; i++) cin >> card[i];
	sort(card.begin(), card.end());
	cin >> M;
	l = 0; r = N - 1;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		l = 0, r = N - 1;
		int b = 0;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (card[m] == num)
			{
				b = 1;
				break;
			}
			if (card[m] > num)
				r = m - 1;
			else
				l = m + 1;
		}
		ans.push_back(b);
	}
	for (int a : ans) cout << a << " "; cout << '\n';
}

// https://www.acmicpc.net/problem/10815