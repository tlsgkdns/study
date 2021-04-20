#include <iostream>

using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int add = 0;
	int through = 1;
	for (int room = 1; room < n; room += add)
	{
		through++;
		add += 6;
	}

	cout << through << endl;
	return 0;
}



// https://www.acmicpc.net/problem/2292