#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 40001;
vector<int> hole;
int depth[MAX], water[MAX];
int N, X1, Y1, X2, Y2, K, E, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> X1 >> Y1;
	for (int i = 0; i < (N / 2) - 1; i++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		for (int j = X1; j < X2; j++)
			depth[j] = Y1;
	}
	cin >> E >> Y1;
	cin >> K;
	for (int k = 0; k < K; k++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		int idx = X1;
		int bot = depth[idx];
		for (int i = idx; i >= 0; i--)
		{
			bot = min(depth[i], bot);
			water[i] = max(bot, water[i]);

		}
		bot = depth[idx];
		for (int i = idx + 1; i < E; i++)
		{
			bot = min(depth[i], bot);
			water[i] = max(bot, water[i]);
		}
	}
	for (int i = 0; i < E; i++)
		ans += (depth[i] - water[i]);
	cout << ans << '\n';
}


// https://www.acmicpc.net/problem/8982