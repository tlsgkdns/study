#include <iostream>

using namespace std;

int X, N, A, B, S = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> X;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		S += (A * B);
	}
	if (S == X) cout << "Yes\n";
	else cout << "No\n";
}

// https://www.acmicpc.net/problem/25304