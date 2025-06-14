#include <iostream>
using namespace std;
double R, PI = 3.141592653589;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R;
	cout << fixed; cout.precision(6);
	cout << R * R * PI << '\n' << R * R * 2 << '\n';
}

// https://www.acmicpc.net/problem/3053