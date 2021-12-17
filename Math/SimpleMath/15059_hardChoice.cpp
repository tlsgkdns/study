#include <iostream>
#include <algorithm>
using namespace std;

int Ca, Ba, Pa, Cr, Br, Pr;
int main()
{
	cin >> Ca >> Ba >> Pa;
	cin >> Cr >> Br >> Pr;
	int ans = max(Cr - Ca, 0) + max(Br - Ba, 0) + max(Pr - Pa, 0);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/15059