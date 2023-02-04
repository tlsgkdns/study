#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll N, A[100001], idx = 0, ans = 0, target = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	while (idx < N)
	{
		ll tmp = A[idx], cnt = 0;
		if (target == tmp)
		{
			while (++idx < N && tmp == A[idx]);
			++target;
		}
		else
		{
			ans += tmp - target++;
			++idx;
		}
	}
	cout << ans << '\n';
}


// https://www.acmicpc.net/problem/16678