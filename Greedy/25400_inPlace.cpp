#include <iostream>
using namespace std;
int N, ans = 0, num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (ans + 1 == num) ++ans;
	}
	cout << N - ans << '\n';
}

// https://www.acmicpc.net/problem/25400