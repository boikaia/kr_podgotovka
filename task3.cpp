#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//бинарный поиск
long binpoisk(vector <long> arr, int l, int r, long x)
{
	if(r>=l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return binpoisk(arr, l, mid - 1, x);
		return binpoisk(arr, mid + 1, r, x);
	}
	return -2;
}

int main()
{
	int n, k,i;
	cin >> n;

	vector<long> A(n);

	for (i = 0; i < n; i++)
		cin >> A[i];

	cin >> k;
	vector<long> B(k);

	for (i = 0; i < k; i++)
	 cin >> B[i];
	
	for (i = 0; i < k; i++)
	 cout << binpoisk(A, 0, n - 1, B[i])+1 << " ";
	
    return 0;
}

