#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool FindFunc(int value)
{
	if (value > 15)
		return true;
	return false;
}

class Player
{
public:
	int _hp;
	int _atk;
};

int main()
{
	vector<int> v;

	v = { 5, 1, 3, 112, 10, 9, 50, 30, 3 };

	// 1.  1�� �ִ��� ã���ּ���. �׸��� index�� Ȥ�� iterator�ڸ��� ã���ּ���
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

	// 2.  15���� ū ���� �ִ��� ã���ּ���. �׸��� iterator �ڸ��� ã���ּ���.(iter, algorithm)
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 15)
			break;
	}

	// pred : bool <vector�� ���� �ڷ���>

	struct FindFunctor
	{
		bool operator()(int value)
		{
			if (value > compareNum)
				return true;
			return false;
		}

		int compareNum = 0;
	};

	FindFunctor functor;
	functor.compareNum = 20;
	iter = std::find_if(v.begin(), v.end(), functor); // �Լ���ü, Ȥ�� �Լ������� ... Callable ��ü
	if (iter != v.end())
		cout << *iter << endl;

	// 3. ��� ���� 50���� ������ bool���� �˷��ּ���. (iter, algorithm)

	struct FindFunctor
	{
		bool operator()(int value)
		{
			if (value < compareNum)
				return true;
			return false;
		}
		int compareNum = 0;

	};

	FindFunctor functor2;
	functor2.compareNum = 50;
	iter = std::find_if(v.begin(), v.end(), functor2); // �Լ���ü, Ȥ�� �Լ������� ... Callable ��ü
	if (iter != v.end())
		cout << *iter << endl;



	// 4. �ϳ��� 30���� ū ���� �ִ��� bool���� �˷��ּ���. (iter, algorithm)

	bool any_bigger_than_30 = true;

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 30)
		{
			any_bigger_than_30 = true;
			break;
		}

	}

	if (any_bigger_than_30)
	{
		cout << "30���� ū ���� �ֽ��ϴ�." << endl;
	}

	bool any_bigger_than_30_2 = std::any_of(v.begin(), v.end(), [](int i) { return i > 30; });
	if (any_bigger_than_30_2)
	{
		cout << "30���� ū ���� �ֽ��ϴ�." << endl;
	}


	// 5. ���Ұ� 3�� ���ҵ��� ������ �˷��ּ���. algorithm
	int count_3 = std::count(v.begin(), v.end(), 3);
	cout << "���Ұ� 3�� ���ҵ��� ����: " << count_3 << endl;

	// 6. ���Ұ� 5���� ū ���ҵ��� ������ �˷��ּ���. algorithm
	int count_if_5 = std::count_if(v.begin(), v.end(), [](int i) { return i > 5; });
	cout << "���Ұ� 5���� ū ���ҵ��� ����: " << count_if_5 << endl;

	// 7. ��� ���ҿ� 3�� �����ּ���. algorithm
	for_each(v.begin(), v.end(), [](int i) { i *= 3; });
	// ���Ͱ� �ٽ� ������� �����
	for_each(v.begin(), v.end(), [](int i) { i /= 3; });
		
	// 8. �ߺ��� ���ҵ��� '����'���ּ���. algorithm
	std::sort(v.begin(), v.end());
	vector<int>::iterator iter2 = std::unique(v.begin(), v.end());
	v.erase(iter2, v.end());
	// 9. ���Ұ� 11�� ���Ҹ� �����ּ���. iter, algorithm
	remove(v.begin(), v.end(), 11);
	// 10. ���Ұ� 10���� ���� ���ҵ��� �����ּ���. algorithm
	struct RemoveF
	{
		bool operator()(const int& value)
		{
			if (value < num)
				return true;
			return false;
		}

		int num;
	};

	RemoveF removeF;
	removeF.num = 10;
	v.erase(std::remove_if(v.begin(), v.end(), removeF), v.end());

	iter = v.begin();

	for (iter; iter != v.end(); )
	{
		if (*iter < 50)
		{
			iter = v.erase(iter);
			continue;
		}

		iter++;
	}

	v.push_back(3);
	v.push_back(5);
	v.push_back(1);
	v.push_back(10);
	v.push_back(50);

	struct Comparer
	{
		bool operator()(int a, int b)
		{
			if (a > b)
				return true;
			return false;
		}
	};

	Comparer comparer;

	std::sort(v.begin(), v.end(), greater<int>());

	vector<Player> players;

	players.push_back({ 100,10 });
	players.push_back({ 50,3 });
	players.push_back({ 1000,1 });
	players.push_back({ 30,30 });
	players.push_back({ 70,7 });



	return 0;
}