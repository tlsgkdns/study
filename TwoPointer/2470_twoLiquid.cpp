#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, L[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	sort(L, L + N);
	int l = 0, r = N - 1, ansl = 0, ansr = N - 1;
	while (l < r)
	{
		int n = L[l] + L[r];
		if (abs(L[ansl] + L[ansr]) > abs(n))
		{
			ansl = l;
			ansr = r;
		}
		if (n > 0) --r;
		else ++l;
	}
	cout << L[ansl] << " " << L[ansr] << '\n';
}

// https://www.acmicpc.net/problem/2470