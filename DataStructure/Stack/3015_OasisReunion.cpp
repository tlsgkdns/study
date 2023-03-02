#include <iostream>
#include <stack>
using namespace std;

int N, H;
stack<pair<int, pair<int, int>>> S;
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> H;
		if (S.empty()) S.push({ H, {i, 1} });
		else
		{
			ans += i - S.top().second.first - 1;
			while (!S.empty() && S.top().first < H)
			{
				ans += S.top().second.second;
				S.pop();
			}
			if (!S.empty() && S.top().first == H)
			{
				int tmp = S.top().second.second;
				ans += tmp;
				S.pop();
				if (!S.empty()) ++ans;
				S.push({ H, {i, tmp + 1} });
			}
			else
			{
				if (!S.empty()) ++ans;
				S.push({ H, {i, 1} });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3015