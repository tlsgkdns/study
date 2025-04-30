#include <iostream>

using namespace std;
int A, B, N, a1 = 0, a2 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (A == B) continue;
		if (A < B) a2++;
		else a1++;
	}
	cout << a1 << " " << a2 << '\n';
}

// https://www.acmicpc.net/problem/5523