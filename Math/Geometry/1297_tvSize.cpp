#include <cmath>
#include <iostream>

using namespace std;

int D;
double r = 0, H, W;
int main()
{
	cin >> D >> H >> W;
	r = D / sqrt(H * H + W * W);
	H *= r; W *= r;
	cout << (int)H << " " << (int)W << '\n';
}

// https://www.acmicpc.net/problem/1297