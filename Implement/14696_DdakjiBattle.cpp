#include <iostream>
#include <cstring>
using namespace std;
int N, A[4], B[4], a, b, P;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B));
		cin >> a;
		while (a--)
		{
			cin >> P;
			++A[P - 1];
		}
		cin >> b;
		while (b--)
		{
			cin >> P;
			++B[P - 1];
		}
		int idx = 3;
		for (; idx >= 0; idx--)
		{
			if (A[idx] == B[idx]) continue;
			if (A[idx] > B[idx]) cout << 'A' << '\n';
			else cout << 'B' << '\n';
			break;
		}
		if (idx < 0) cout << 'D' << '\n';
	}
}

// https://www.acmicpc.net/problem/14696