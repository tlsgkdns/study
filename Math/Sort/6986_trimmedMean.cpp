#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> arr;
double N, K;

int main()
{
	cin >> N >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	double s = K, e = N - K;
	double sum = 0, sum2;
	for (int i = s; i < e; i++) sum += arr[i];
	sum2 = sum;
	for (int i = 0; i < K; i++)
	{
		sum2 += arr[s];
		sum2 += arr[e - 1];
	}
	sum /= (e - s); sum2 /= N;
	printf("%.2lf\n", sum + 0.00000001);
	printf("%.2lf\n", sum2 + 0.00000001);
}

// https://www.acmicpc.net/problem/6986