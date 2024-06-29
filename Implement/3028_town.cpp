#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int W, C[3];
string D;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	C[0] = 1;
	cin >> D;
	for (int i = 0; i < D.size(); i++)
	{
		if (D[i] == 'A') swap(C[0], C[1]);
		if (D[i] == 'B') swap(C[1], C[2]);
		if (D[i] == 'C') swap(C[0], C[2]);
	}
	for (int i = 0; i < 3; i++)
	{
		if (C[i] == 1)
		{
			cout << i + 1 << '\n';
			break;
		}
	}
}

// https://www.acmicpc.net/problem/3028