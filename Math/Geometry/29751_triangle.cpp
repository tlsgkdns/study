#include <iostream>
#include <cmath>

using namespace std;
double W, H;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cout.precision(1); cout << fixed;
	cin >> W >> H;
	cout << W * H * 0.5 << '\n';
}

// https://www.acmicpc.net/problem/29751