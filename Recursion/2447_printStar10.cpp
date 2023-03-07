#include <iostream>
#include <cstdio>
using namespace std;

int N;
void printStar(int y, int x, int n)
{
	if ((y / n) % 3 == 1 && (x / n) % 3 == 1)
	{
		cout << " ";
		return;
	}
	if (n / 3 == 0) cout << "*";
	else printStar(y, x, n / 3);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printStar(i, j, N);
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2447