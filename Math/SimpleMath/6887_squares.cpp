#include <iostream>
#include <cmath>

using namespace std;

int L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	cout << "The largest square has side length " << int(sqrt(L)) << ".\n";
}

// https://www.acmicpc.net/problem/6887