#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int area = 0;
	vector<vector<bool>> loc(101, vector<bool>(101, false));

	for (int i = 0; i < 4; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int m = a; m < c; m++)
		{
			for (int n = b; n < d; n++)
				if (!loc[m][n])
				{
					loc[m][n] = true;
					area++;
				}
		}
	}

	cout << area << endl;
	return 0;
}

// https://www.acmicpc.net/problem/2669