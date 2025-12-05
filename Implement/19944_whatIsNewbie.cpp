#include <iostream>

using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	if (M == 1 || M == 2) cout << "NEWBIE!\n";
	else if (M <= N) cout << "OLDBIE!\n";
	else cout << "TLE!\n";
}

// https://www.acmicpc.net/problem/19944