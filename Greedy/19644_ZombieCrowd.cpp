#include <iostream>
#include <algorithm>
using namespace std;

long long L, ML, MK, C, Z[3000002], A[3000002];
bool ans = true;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	cin >> ML >> MK;
	cin >> C;
	for (int i = 1; i <= L; i++) cin >> Z[i];
	A[0] = 0;
	for (int i = 1; i <= L; i++)
	{
		if (Z[i] - (A[i - 1] - A[max(i - ML, (long long)0)]) * MK > MK)
		{
			if (C == 0)
			{
				ans = false;
				break;
			}
			else
			{
				A[i] = A[i - 1];
				--C;
			}
		}
		else
		{
			A[i] = A[i - 1] + 1;
		}
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/19644