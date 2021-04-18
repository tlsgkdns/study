#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
	list<int> student;

	for (int i = 1; i <= 30; i++)
		student.push_back(i);

	for (int j = 0; j < 28; j++)
	{
		int submit;
		cin >> submit;
		student.remove(submit);
	}

	for (int s : student) cout << s << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/5597