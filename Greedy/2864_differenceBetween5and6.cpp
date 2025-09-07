#include <iostream>
#include <string>
using namespace std;

string A1, B1, A2, B2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A1 >> B1;
	A2 = A1; B2 = B1;
	for (int i = 0; i < A1.size(); i++)
		if (A1[i] == '5')
			A1[i] = '6';
	for (int i = 0; i < A2.size(); i++)
		if (A2[i] == '6')
			A2[i] = '5';
	for (int i = 0; i < B1.size(); i++)
		if (B1[i] == '5')
			B1[i] = '6';
	for (int i = 0; i < B2.size(); i++)
		if (B2[i] == '6')
			B2[i] = '5';
	cout << stoi(A2) + stoi(B2) << " " << stoi(A1) + stoi(B1) << '\n';
}

// https://www.acmicpc.net/problem/2864