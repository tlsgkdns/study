#include <iostream>
using namespace std;
int Y, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> M;
	cout << M + (M - Y) << '\n';
}

// https://www.acmicpc.net/problem/6749