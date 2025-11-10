#include <iostream>
using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	if (N * 100 >= M) cout << "Yes\n";
	else cout << "No\n";
}

// https://www.acmicpc.net/problem/27959