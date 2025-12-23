#include <iostream>

using namespace std;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cout << "a";
	cout << '\n';
}

// https://www.acmicpc.net/problem/20944