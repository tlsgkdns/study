#include <iostream>
#include <algorithm>

using namespace std;
int N, C[100004], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];
	sort(C, C + N, greater<int>());
	while (N % 3 > 0) ++N;
	for (int i = 2; i < N; i += 3)
		ans += C[i - 1] + C[i - 2];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11508