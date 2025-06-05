#include <iostream>
#include <algorithm>

using namespace std;
int N, A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int r = 0;
		for (int j = 0; j < 5; j++)
		{
			cin >> A;
			r = max(A, r);
		}
		cout << "Case #" << i << ": " << r << '\n';
	}
}

// https://www.acmicpc.net/problem/9699