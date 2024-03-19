#include <iostream>
#include <algorithm>
using namespace std;

int K, R, C, D[6], L[6], ridx = 0, cidx = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> K;
	for (int i = 0; i < 6; i++)
	{
		cin >> D[i] >> L[i];
		if (D[i] <= 2 && C < L[i])
		{
			cidx = i;
			C = L[i];
		}
		else if (D[i] >= 3 && R < L[i])
		{
			ridx = i;
			R = L[i];
		}
	}
	if (cidx == (ridx + 1) % 6) swap(ridx, cidx);
	cout << (((R * C) - (L[(ridx + 2) % 6] * L[(ridx + 3) % 6])) * K) << '\n';
}

// https://www.acmicpc.net/problem/2477