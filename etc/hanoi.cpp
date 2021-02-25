#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int, int>> mv;
int N, ans = 0;
void hanoi(int n, int from, int tmp, int to)
{
	if (n == 1)
	{
		mv.push_back(make_pair(from, to));
		ans++;
		return;
	}
	hanoi(n - 1, from, to, tmp);
	hanoi(1, from, tmp, to);
	hanoi(n - 1, tmp, from, to);
}

int main()
{
	cin >> N;
	if (N <= 20)
		hanoi(N, 1, 2, 3);
	cout << ans << '\n';
	for (auto m : mv) cout << m.first << " " << m.second << '\n';
}

// https://www.acmicpc.net/problem/11729

/*
reviewing recursion algorithm
*/