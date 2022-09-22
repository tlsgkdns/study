#include <iostream>
#include <algorithm>
using namespace std;

int N, L, ans = 1;
int H[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> H[i];
	sort(H, H + N);
	int R = L - 1;
	for (int i = 1; i < N; i++)
	{
		int S = H[i] - H[i - 1];
		if (R >= S)
			R -= S;
		else
		{
			R = L - 1;
			ans++;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1449