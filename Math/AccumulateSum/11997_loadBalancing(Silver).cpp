#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

vector<pair<int, int>> coord;
vector<vector<int>> acc;
vector<int> coordX, coordY, dicX, dicY;
int N, endX, endY;

int maxCow(int x, int y)
{
	int a1 = acc[x][y], a2 = acc[endX - 1][y] - acc[x][y];
	int a3 = acc[x][endY - 1] - acc[x][y];
	int a4 = N - (a1 + a2 + a3);
	return max(a1, max(a2, max(a3, a4)));
}
int main()
{
	cin >> N; coord.resize(N);
	dicX.resize(MAX); dicY.resize(MAX);
	for (int i = 0; i < N; i++)
	{
		cin >> coord[i].first >> coord[i].second;
		coordX.push_back(coord[i].first);
		coordY.push_back(coord[i].second);
	}
	sort(coordX.begin(), coordX.end()); sort(coordY.begin(), coordY.end());
	coordX.erase(unique(coordX.begin(), coordX.end()), coordX.end());
	coordY.erase(unique(coordY.begin(), coordY.end()), coordY.end());
	for (int i = 0; i < coordX.size(); i++) dicX[coordX[i]] = i;
	for (int i = 0; i < coordY.size(); i++) dicY[coordY[i]] = i;
	endX = coordX.size(); endY = coordY.size();
	acc.resize(endX, vector<int>(endY, 0));
	for (int i = 0; i < N; i++) acc[dicX[coord[i].first]][dicY[coord[i].second]]++;
	for (int i = 1; i < endX; i++) acc[i][0] += acc[i - 1][0];
	for (int i = 1; i < endY; i++) acc[0][i] += acc[0][i - 1];
	for (int i = 1; i < endX; i++)
		for (int j = 1; j < endY; j++)
			acc[i][j] += acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
	int ans = MAX * 2;
	for (int i = 0; i < endX; i++)
		for (int j = 0; j < endY; j++)
			ans = min(ans, maxCow(i, j));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11997