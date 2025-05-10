#include <iostream>
#include <vector>

using namespace std;

vector<int> v = { 10, - 4, 3, 1, 5, 6, - 35, 12, 21, - 1 };
vector<int> cache;
int n = 0;

// LIS(9) -1
// LIS(8) 21
// LIS(7) 33
// LIS(6) -2
// LIS(5) 6
// LIS(4) 11
// LIS(3) 12
// LIS(2) 15
// LIS(1) 11
// LIS(0) 21

void Input()
{
	v.clear();
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;

		v.push_back(temp);
	}
}

int Lis(int pos)
{
	if (pos == v.size() - 1)
		return v[pos];

	int& ref = cache[pos];
	if (ref != -2147483647 - 1)
		return ref;

	int result = v[pos];

	result = max(result, result + Lis(pos + 1));

	return ref = result;
}

int main()
{
	Input();
	cache = vector<int>(n, -2147483647 - 1);

	
	int result = -2147483647 - 1;
	for (int i = 0; i < v.size(); i++)
	{
		result = max(result, Lis(i));
	}

	cout << result << endl;

	return 0;
}