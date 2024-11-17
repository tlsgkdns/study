#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, A, B;
int num1[101], num2[101], cnt1[101], cnt2[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		num1[A]++; num2[B]++;
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		int l = 1, r = 99, ans = 0;
		while (r > 0)
		{
			while (l < 100 && num1[l] - cnt1[l] == 0) ++l;
			while (r > 0 && num2[r] - cnt2[r] == 0) --r;
			if (r <= 0) break;
			ans = max(ans, (r + l));
			int m = min(num1[l] - cnt1[l], num2[r] - cnt2[r]);
			cnt1[l] += m;
			cnt2[r] += m;
		}
		cout << ans << '\n';
	}
}