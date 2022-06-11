#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int H, W, ans = 0;
int height[501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	for (int i = 0; i < W; i++) cin >> height[i];
	stack<int> s;
	int ans = 0;
	for (int i = 0; i < W; i++)
	{
		int f = -1;
		while (!s.empty() && height[s.top()] <= height[i])
		{
			int w = (i - s.top() - 1);
			int h = height[s.top()] - f;
			ans += w * h;
			f = max(f, height[s.top()]);
			s.pop();
		}
		if (!s.empty()) ans += (i - s.top() - 1) * (height[i] - f);
		s.push(i);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14719