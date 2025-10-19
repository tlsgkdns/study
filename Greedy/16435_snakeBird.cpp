#include <iostream>
#include <algorithm>

using namespace std;
int N, L, H[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> H[i];
	sort(H, H + N);
	for (int i = 0; i < N; i++)
		if (H[i] <= L)
			++L;
	cout << L << '\n';
}

// https://www.acmicpc.net/problem/16435