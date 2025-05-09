#include <iostream>
#include <string>

using namespace std;

string A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;
	cout << stoi(A) + stoi(B) - stoi(C) << '\n';
	cout << stoi(A + B) - stoi(C) << '\n';
}

// https://www.acmicpc.net/problem/31403