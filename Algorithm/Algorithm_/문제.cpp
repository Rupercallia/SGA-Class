#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>>cache(101, vector<vector<int>>(101, vector<int>(101, -1)));

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}

	int& ref = cache[a][b][c];
	if (ref != -1)
		return ref;

	if (a < b && b < c)
	{
		ref = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}

	else
	{
		ref = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

	return ref;
}
int main()
{
	int a = 50;
	int b = 50;
	int c = 50;

	/*cin >> a;
	cin >> b;
	cin >> c;*/

	cout << "w(" << a << "," << b << "," << c << ") = " << w(a, b, c) << endl;

	return 0;
}
