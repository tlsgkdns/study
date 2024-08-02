#include <iostream>

using namespace std;

int N, num = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		++num;
		if (N % 2) cout << num << ". odd " << (N - 1) / 2 << '\n';
		else cout << num << ". even " << N / 2 << '\n';
	}
}

// https://www.acmicpc.net/problem/4892