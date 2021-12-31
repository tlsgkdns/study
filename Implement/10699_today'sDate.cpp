#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	time_t timer = time(NULL);
	struct tm* curr = localtime(&timer);
	cout << curr->tm_year + 1900 << "-" << curr->tm_mon + 1 << "-" << curr->tm_mday << '\n';
}

// https://www.acmicpc.net/problem/10699