#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> neg, pos;
int N, M, B, a1 = 0, a2 = 0, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> B;
		if (B < 0) neg.push_back(-B);
		else pos.push_back(B);
	}
	sort(neg.begin(), neg.end()); sort(pos.begin(), pos.end());
	for (int i = ((neg.size() % M == 0) ? M - 1 : (neg.size() % M) - 1); i < neg.size(); i += M)
		ans += 2 * neg[i];
	for (int i = ((pos.size() % M == 0) ? M - 1 : (pos.size() % M) - 1); i < pos.size(); i += M)
		ans += 2 * pos[i];
	a1 = (neg.empty() ? 0 : neg.back()); a2 = (pos.empty() ? 0 : pos.back());
	ans -= max(a1, a2);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1461