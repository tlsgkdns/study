#include <iostream>
#include <cmath>

using namespace std;

long long N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cout << abs(N - M) << '\n';
}

// https://www.acmicpc.net/problem/2420