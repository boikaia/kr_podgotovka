#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main()
{
	int n,i;
	long long a, x;
	string kom;

	cin >> n;
	x = 0;

	stack <long long> st;
	for(i=0;i<n;i++)
	{
		cin >> kom;
		if(kom=="Insert")
		{
			cin >> a;
			if (!st.empty()) x = st.top();
			if (a >= x) st.push(a);
			else { st.pop(); st.push(a); st.push(x); }
		}
		if (kom == "ExtractMax")
			if (!st.empty())
			cout << st.top() << endl;
	}
    return 0;
}
