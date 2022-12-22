#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		int X, N, l, L1 = -1, L2 = -1;
		vector<int> L;
		cin >> X;
		if (cin.eof()) break;
		X *= 10000000;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> l;
			L.push_back(l);
		}
		sort(L.begin(), L.end());
		for (int i = 0; i + 1 < N && L[i] * 2 <= X; i++)
		{
			auto l2 = lower_bound(L.begin() + i + 1, L.end(), X - L[i]);
			if (l2 != L.end() && *l2 + L[i] == X)
			{
				L1 = L[i]; L2 = *l2;
				break;
			}
		}
		if (L1 < 0) cout << "danger\n";
		else cout << "yes " << L1 << " " << L2 << '\n';
	}
}

// https://www.acmicpc.net/problem/3649