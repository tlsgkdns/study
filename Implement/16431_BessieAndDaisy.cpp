#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int Br, Bc, Dr, Dc, Jr, Jc;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> Br >> Bc >> Dr >> Dc >> Jr >> Jc;
	int d1 = max(abs(Br - Jr), abs(Bc - Jc));
	int d2 = abs(Dr - Jr) + abs(Dc - Jc);
	if (d1 < d2) cout << "bessie\n";
	else if (d1 > d2) cout << "daisy\n";
	else cout << "tie\n";
}

// https://www.acmicpc.net/problem/16431