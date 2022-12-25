#include <iostream>
#include <algorithm>
using namespace std;
int L, P, V, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;
		++cnt;
		int ans = (V / P) * L;
		ans += min(V % P, L);
		cout << "Case " << cnt << ": " << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/4796