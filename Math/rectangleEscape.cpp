
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


int main()
{
	string buf;
	vector<int> input;
	getline(cin, buf);

	stringstream iss(buf);
	string tmp;
	while (getline(iss, tmp, ' '))
	{
		input.push_back(stoi(tmp));
	}

	int ret = min(min(min((input[2] - input[0]), (input[3] - input[1])), input[0]), input[1]);
	cout << ret << endl;
	return 0;
}

// https://www.acmicpc.net/problem/1085

/*
just calculate
*/