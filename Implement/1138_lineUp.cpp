#include <iostream>
#include <vector>
using namespace std;
int N, h[11];
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> h[i];
	ans.push_back(N);
	for (int i = N - 1; i > 0; i--)
		ans.insert(ans.begin() + h[i], i);
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1138