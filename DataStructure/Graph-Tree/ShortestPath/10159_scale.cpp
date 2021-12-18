#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> scale;
const int INF = 1000000000;
int N, M, a, b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	scale.resize(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		scale[a][b] = true;
	}
	vector<vector<bool>> tmp = scale;
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (scale[i][k] && scale[k][j])
					scale[i][j] = true;
	vector<int> ans;
	for (int i = 1; i <= N; i++)
	{
		int a = N - 1;
		for (int j = 1; j <= N; j++)
			if (scale[i][j] || scale[j][i])
				a--;
		ans.push_back(a);
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/10159