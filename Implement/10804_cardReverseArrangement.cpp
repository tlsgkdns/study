#include <iostream>
using namespace std;
int C[21], A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	for (int i = 1; i <= 20; i++) C[i] = i;
	for (int i = 0; i < 10; i++)
	{
		cin >> A >> B;
		for (int l = A, r = B; l < r; l++, r--)
		{
			swap(C[l], C[r]);
		}
	}
	for (int i = 1; i <= 20; i++) cout << C[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/10804