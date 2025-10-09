#include <iostream>

using namespace std;

int N, ans1 = 0, ans2 = 0;

int main()
{
	cin >> N;

	ans1 = N * 0.78;
	ans2 = N * 0.956;
	cout << ans1 << '\n' << ans2 << '\n';
}


// https://www.acmicpc.net/problem/20492