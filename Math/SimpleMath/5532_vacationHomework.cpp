#include <iostream>
#include <algorithm>
using namespace std;

int L, A, B, C, D, S = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L >> A >> B >> C >> D;
	S += (A % C > 0) + (A / C);
	S = max((B % D > 0) + (B / D), (A % C > 0) + (A / C));
	cout << L - S << '\n';
}

// https://www.acmicpc.net/problem/5532