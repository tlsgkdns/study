#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int H, W;
vector<vector<int>> A(101, vector<int>(101, 0));

vector<int> sortedArr(vector<int>& arr, int l)
{
	vector<int> ret, freq(101, 0);
	vector<pair<int, int>> f;
	for (int i = 0; i < l; i++)
	{
		if (arr[i] == 0) continue;
		freq[arr[i]]++;
	}
	for (int n = 1; n <= 100; n++)
	{
		if (freq[n] == 0) continue;
		f.push_back({ freq[n], n });
	}
	sort(f.begin(), f.end());
	for (auto p : f)
	{
		ret.push_back(p.second);
		ret.push_back(p.first);
	}
	return ret;
}
vector<int> getColumn(int idx)
{
	vector<int> ret;
	for (int i = 0; i < H; i++)
		ret.push_back(A[i][idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	H = 3; W = 3;
	int t = 0;
	for (; t <= 100; t++)
	{
		if (A[r - 1][c - 1] == k) break;
		if (H >= W)
		{
			int tmp = W;
			for (int h = 0; h < H; h++)
			{
				vector<int> nArr = sortedArr(A[h], W);
				for (int w = 0; w < W; w++)
					A[h][w] = 0;
				int nL = min(100, (int)nArr.size());
				tmp = max(tmp, nL);
				for (int w = 0; w < nL; w++)
					A[h][w] = nArr[w];
			}
			W = tmp;
		}
		else
		{
			int tmp = H;
			for (int w = 0; w < W; w++)
			{
				vector<int> col = getColumn(w);
				vector<int> nArr = sortedArr(col, H);
				for (int h = 0; h < W; h++)
					A[h][w] = 0;
				int nL = min(100, (int)nArr.size());
				tmp = max(tmp, nL);
				for (int h = 0; h < nL; h++)
					A[h][w] = nArr[h];
			}
			H = tmp;
		}
	}
	if (t > 100) cout << -1 << '\n';
	else cout << t << '\n';
}

// https://www.acmicpc.net/problem/17140