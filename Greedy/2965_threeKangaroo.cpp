#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;
	cout << max(C - B, B - A) - 1 << '\n';
}

// https://www.acmicpc.net/problem/2965