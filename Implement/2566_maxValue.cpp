#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
int A[9][9], r = 0, c = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> A[i][j];
			if (A[r][c] < A[i][j])
			{
				r = i;
				c = j;
			}
		}
	cout << A[r][c] << '\n';
	cout << r + 1 << " " << c + 1 << '\n';
}

// https://www.acmicpc.net/problem/2566