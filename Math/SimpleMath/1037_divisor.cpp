#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int A, N;
	cin >> N;
	int mn = 1000001, mx = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		mn = min(mn, A);
		mx = max(mx, A);
	}
	cout << mx * mn << '\n';
}

// https://www.acmicpc.net/problem/1037