#include <iostream>
#include <bitset>

using namespace std;
bitset<33554433> B;
int A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> A;
		if (cin.eof()) break;
		if (B.test(A)) continue;
		B.set(A);
		cout << A << " ";
	}
}

// https://www.acmicpc.net/problem/13701