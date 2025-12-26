#include <iostream>
using namespace std;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	cout << (N / M) + (N % M > 0) << '\n';
}

// https://www.acmicpc.net/problem/34891