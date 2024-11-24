#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	if (N % 2 > 0) cout << "Goose\n";
	else cout << "Duck\n";
}

// https://www.acmicpc.net/problem/30455