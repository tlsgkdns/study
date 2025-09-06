#include <iostream>
#include <string>
using namespace std;

string A, H;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A;
	cin >> H;
	if (A.size() < H.size()) cout << "no\n";
	else cout << "go\n";
}

// https://www.acmicpc.net/problem/4999