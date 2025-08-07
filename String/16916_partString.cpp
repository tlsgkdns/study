#include <iostream>
#include <cstring>
using namespace std;

string S, P;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S >> P;
	cout << (strstr(S.c_str(), P.c_str()) != NULL) << '\n';
}

// https://www.acmicpc.net/problem/16916