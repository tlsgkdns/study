#include <iostream>
using namespace std;

int M, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> K;
	if (M % K > 0) cout << "No\n";
	else cout << "Yes\n";
}

// https://www.acmicpc.net/problem/31450