#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> num;
int N, A[100001], X, ans = 0, cnt[2000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (cnt[A[i]] == 0) num.push_back(A[i]);
		++cnt[A[i]];
	}
	cin >> X;
	sort(num.begin(), num.end());
	int l = 0, r = num.size() - 1;
	while (l < r)
	{
		if (num[l] + num[r] > X)
		{
			--r;
		}
		else
		{
			if (num[l] + num[r] == X) ans += cnt[num[l]] * cnt[num[r]];
			++l;
		}
	}
	if (X % 2 == 0)
	{
		int h = X / 2;
		if (cnt[h] > 1)
			ans += cnt[h] * (cnt[h] - 1) / 2;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3273