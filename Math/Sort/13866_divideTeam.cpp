#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int S[4];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	for (int i = 0; i < 4; i++) cin >> S[i];
	sort(S, S + 4);
	cout << abs(S[3] + S[0] - S[1] - S[2]) << '\n';
}

// https://www.acmicpc.net/problem/13866