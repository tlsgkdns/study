#include <iostream>
#include <vector>
using namespace std;

int H, W, X, Y;
vector<vector<int>> arr, ans;
int main()
{
	cin >> H >> W >> X >> Y;
	ans.resize(H, vector<int>(W));
	arr.resize(H + X, vector<int>(W + Y));
	for (int i = 0; i < H + X; i++)
		for (int j = 0; j < W + Y; j++)
			cin >> arr[i][j];
	for (int i = 0; i < X; i++)
		for (int j = 0; j < W; j++)
			ans[i][j] = arr[i][j];
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < H; j++)
			ans[j][i] = arr[j][i];
	for (int i = X; i < H; i++)
		for (int j = Y; j < W; j++)
			ans[i][j] = arr[i][j] - ans[i - X][j - Y];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16967