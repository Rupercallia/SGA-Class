#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> v;

	v = { 5, 1, 3, 112, 10, 9, 50, 30 };

	//1. 1�� �ִ��� ã���ּ���. �׸��� index�� Ȥ�� iterator�ڸ��� ã���ּ���.

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == 1)
			break;
	}

	iter = std::find(v.begin(), v.end(), 0);
		if (iter == v.end())
		{
			cout << "��ã�ҽ��ϴ�." << endl;
		}
		else
		{
			cout << *iter << endl;
		}


	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 15)
			break;
	}
}