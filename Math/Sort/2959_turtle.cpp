#include <iostream>
#include <algorithm>

using namespace std;
int R[4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++) cin >> R[i];
	sort(R, R + 4);
	cout << R[0] * R[2] << '\n';
}

// https://www.acmicpc.net/problem/2959