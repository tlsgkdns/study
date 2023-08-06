#include <iostream>
#include <cmath>
using namespace std;
int T, A, B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		if (A > B) swap(A, B);
		while ((int)log2(A) < (int)log2(B)) B /= 2;
		while (A != B)
		{
			A /= 2;
			B /= 2;
		}
		cout << A * 10 << '\n';
	}
}

// https://www.acmicpc.net/problem/13116