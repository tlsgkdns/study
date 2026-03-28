#include <iostream>

using namespace std;

int N, A, t = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) cin >> A;
		cout << "Case " << t++ << ": Sorting... done!\n";
	}
}

// https://www.acmicpc.net/problem/23235