#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, A, T;
pii tmp, p;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (i == 0)
		{
			T = A;
			continue;
		}
		if (i == 1)
		{
			p.first = T; p.second = A;
		}
		tmp.first = max(2 * A - p.second, A);
		tmp.second = 2 * A - p.first;
		p = tmp;
	}
	cout << max(tmp.second - tmp.first + 1, 0) << '\n';
}

// https://www.acmicpc.net/problem/5485