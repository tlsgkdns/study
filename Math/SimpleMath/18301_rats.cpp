#include <iostream>
#include <cmath>

using namespace std;

double n1, n2, n12;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n1 >> n2 >> n12;
	cout << floor((n1 + 1) * (n2 + 1) / (n12 + 1) - 1) << '\n';
}

// https://www.acmicpc.net/problem/18301