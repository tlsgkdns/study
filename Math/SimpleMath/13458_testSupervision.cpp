#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	int n;
	vector<float> a;
	int b, c;
	double tmp;
	long long int answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	cin >> b >> c;

	for (double t : a)
	{
		answer++;
		t -= b;
		if (t <= 0) continue;
		answer += ceil(t / c);
	}

	cout << answer << endl;

	return 0;
}

// https://www.acmicpc.net/problem/13458