#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> S;
int N, A[51], ans = 100;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		S.insert(A[i]);
	}
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int s = 0; s < 5; s++)
			cnt += (S.find(A[i] + s) == S.end());
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1337