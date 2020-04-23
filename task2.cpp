#include "stdafx.h"
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct bu
{
	char a;
	int v;
	deque <bool> kod;
};

struct kombo
{
	vector <char> k;
	int v;
};

bool cmp(kombo a, kombo b)
{
	return (a.v > b.v);
}

int main()
{
	string s;
	int n,i,j,l, key;

	cin >> s;
	n = s.length();
	vector <bu> buk; //хранит все различные буквы, их количество в тексте и их код
	vector <kombo> kom; //хранит результаты слияния букв и встречаемость в тексте
	for (i = 0; i < n; i++) //поиск новых букв и заполнение 2 массивов
	{
		key = 0;
		for (j = 0; j < buk.size(); j++)
			if (s[i] == buk[j].a)
			{
				buk[j].v++; kom[j].v++; key = 1; break;
			}
		if (key == 0) {
			buk.resize(j + 1); kom.resize(j + 1);
			buk[j].v = 1; kom[j].v = 1;
			buk[j].a=s[i]; kom[j].k.push_back(s[i]);
			}
	}
	if (buk.size() == 1) 
  { // случай с одной буквой
		cout << "1 "<<n<<endl;
    cout<<s[0]<<" 0"<<endl;
    for (i=0;i<n;i++)
    cout<<"0";
    return 0;
    }
	n = l = kom.size(); cout << n << " ";
  //реализация алгоритма Хаффмана
	while (n > 1)
	{		
		stable_sort(kom.begin(), kom.end(), cmp);
		for(i=0;i<kom[n-1].k.size();i++)
		for (j = 0; j < l; j++)
			if (kom[n-1].k[i] == buk[j].a)
			{
				buk[j].kod.push_front(1); break;
			}
		for (i = 0; i<kom[n - 2].k.size(); i++)
		for (j = 0; j < l; j++)
			if (kom[n - 2].k[i] == buk[j].a)
			{
				buk[j].kod.push_front(0); break;
			}
		for (i = 0; i<kom[n - 1].k.size(); i++)
			kom[n-2].k.push_back(kom[n-1].k[i]);
		kom[n - 2].v += kom[n - 1].v;
		kom.pop_back(); n--;
	}
  // вывод необходимых данных на основе массива buk
	long long dlin=0;
	for (j = 0; j < l; j++)
		dlin += buk[j].v*buk[j].kod.size();
	cout << dlin << endl;
	for (j = 0; j < l; j++)
	{
		cout << buk[j].a << ": ";
		for (i = 0; i < buk[j].kod.size(); i++)
			cout << buk[j].kod[i];
		cout << endl;
	}
	for (j = 0; j < s.size(); j++)
	{
		for (int f = 0; f < l; f++)
			if (s[j] == buk[f].a)
			{
				for (i = 0; i < buk[f].kod.size(); i++)
					cout << buk[f].kod[i];
				break;
			}
	}
    return 0;
}

