#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = 0;

void solve(int num)
{
	if (num > N) return;
	ans = max(ans, num);
	solve(num * 10 + 4);
	solve(num * 10 + 7);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1526