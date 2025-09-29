#include <iostream>

using namespace std;

int N, L, n = 1;

bool chk()
{
	int num = n;
	while (num > 0)
	{
		if (num % 10 == L) return true;
		num /= 10;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		while (chk()) n++;
		++n;
	}
	cout << n - 1 << '\n';
}

// https://www.acmicpc.net/problem/1681