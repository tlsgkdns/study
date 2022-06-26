#include <iostream>
#include <algorithm>
using namespace std;

float S = 0.0f, E;
float points[3][2];
float getPos(float cen, float pos)
{
	return -(pos - cen) + cen;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> E;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> points[i][j];
		if (points[i][0] > points[i][1])
			swap(points[i][0], points[i][1]);
	}
	for (int idx = 0; idx < 3; idx++)
	{
		if (points[idx][0] == points[idx][1]) continue;
		float cen = (points[idx][0] + points[idx][1]) / 2;
		for (int i = idx + 1; i < 3; i++)
		{
			if (points[i][1] <= cen) continue;
			if (points[i][0] > cen)
				points[i][0] = getPos(cen, points[i][0]);
			points[i][1] = getPos(cen, points[i][1]);
			if (points[i][0] > points[i][1]) swap(points[i][0], points[i][1]);
		}
		S = min(S, getPos(cen, E));
		E = cen;
	}
	cout.precision(1);
	cout << fixed << (E - S) << '\n';
}

// https://www.acmicpc.net/problem/2597