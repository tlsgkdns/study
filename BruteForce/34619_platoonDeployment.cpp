#include <iostream>

using namespace std;

int A, B, N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> A >> B >> N >> K;
	for (int i = 1; i <= A; i++)
		for (int j = 1; j <= B; j++)
			for (int k = 0; k < N; k++)
				if (--K == 0)
				{
					cout << i << " " << j << '\n';
				}
}

// https://www.acmicpc.net/problem/34619