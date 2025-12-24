#include <iostream>

using namespace std;
char c;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> c;
	if (c == 'N' || c == 'n') cout << "Naver D2\n";
	else cout << "Naver Whale\n";
}

// https://www.acmicpc.net/problem/24883