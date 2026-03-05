#include <iostream>

using namespace std;
int H, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> M;
	cout << (H - 9) * 60 + M << '\n';
}

// https://www.acmicpc.net/problem/26307