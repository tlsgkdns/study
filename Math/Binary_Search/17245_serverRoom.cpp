#include <iostream>
using namespace std;
using ll = long long;
int N;
int room[1001][1001];
ll half = 0;
int L = 0, H = 10000001;
bool satisfy(int num)
{
	ll s = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			s += ((room[i][j] > num) ? num : room[i][j]);
	return s >= half;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> room[i][j];
			half += room[i][j];
		}
	half = ((half % 2 == 1) ? ((half / 2) + 1) : (half / 2));
	while (L < H)
	{
		int M = (H + L) / 2;
		if (satisfy(M)) H = M;
		else L = M + 1;
	}
	cout << L << '\n';
}

// https://www.acmicpc.net/problem/17245