#include <iostream>
#include <algorithm>

using namespace std;
int A, B, C, D, E, F, m1 = 1000, m2 = 1000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> D >> E >> F;
	m1 = min(min(A, B), min(C, D)); m2 = min(E, F);
	cout << A + B + C + D + E + F - m1 - m2 << '\n';
}

// https://www.acmicpc.net/problem/11948