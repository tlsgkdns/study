#include <iostream>
#include <string>

using namespace std;

string A, B, C, D;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> D;
	A += B; C += D;
	cout << stoll(A) + stoll(C) << '\n';
}

// https://www.acmicpc.net/problem/10824