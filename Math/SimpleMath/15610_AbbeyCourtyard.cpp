#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, sq; cin >> a;
	sq = sqrt(a); cout.precision(12);
	cout << sq * 4 << '\n';
}
// https://www.acmicpc.net/problem/15610