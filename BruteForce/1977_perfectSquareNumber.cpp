#include <iostream>
#include <cmath>
using namespace std;

int M, N, m = -1, s = 0;
int main()
{
	cin >> M >> N;
	for (int n = ceil(sqrt(M)); n <= sqrt(N); n++)
	{
		if (m == -1) m = n * n;
		s += n * n;
	}
	if (m == -1) cout << -1 << '\n';
	else
		cout << s << '\n' << m << '\n';
}

// https://www.acmicpc.net/problem/1977