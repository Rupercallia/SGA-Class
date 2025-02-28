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

	// 1.  1이 있는지 찾아주세요. 그리고 index나 혹은 iterator자리를 찾아주세요
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == 1)
			break;
	}

	iter = std::find(v.begin(), v.end(), 0);
	if (iter == v.end())
	{
		cout << "못찾았습니다." << endl;
	}
	else
	{
		cout << *iter << endl;
	}

	// 2.  15보다 큰 수가 있는지 찾아주세요. 그리고 iterator 자리를 찾아주세요.(iter, algorithm)
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 15)
			break;
	}

	// pred : bool <vector의 원소 자료형>

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
	iter = std::find_if(v.begin(), v.end(), functor); // 함수객체, 혹은 함수포인터 ... Callable 객체
	if (iter != v.end())
		cout << *iter << endl;

	// 3. 모든 수가 50보다 작은지 bool으로 알려주세요. (iter, algorithm)

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
	iter = std::find_if(v.begin(), v.end(), functor2); // 함수객체, 혹은 함수포인터 ... Callable 객체
	if (iter != v.end())
		cout << *iter << endl;



	// 4. 하나라도 30보다 큰 수가 있는지 bool으로 알려주세요. (iter, algorithm)

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
		cout << "30보다 큰 수가 있습니다." << endl;
	}

	bool any_bigger_than_30_2 = std::any_of(v.begin(), v.end(), [](int i) { return i > 30; });
	if (any_bigger_than_30_2)
	{
		cout << "30보다 큰 수가 있습니다." << endl;
	}


	// 5. 원소가 3인 원소들의 개수를 알려주세요. algorithm
	int count_3 = std::count(v.begin(), v.end(), 3);
	cout << "원소가 3인 원소들의 개수: " << count_3 << endl;

	// 6. 원소가 5보다 큰 원소들의 개수를 알려주세요. algorithm
	int count_if_5 = std::count_if(v.begin(), v.end(), [](int i) { return i > 5; });
	cout << "원소가 5보다 큰 원소들의 개수: " << count_if_5 << endl;

	// 7. 모든 원소에 3을 곱해주세요. algorithm
	for_each(v.begin(), v.end(), [](int i) { i *= 3; });
	// 벡터값 다시 원래대로 만들기
	for_each(v.begin(), v.end(), [](int i) { i /= 3; });
		
	// 8. 중복된 원소들을 '제거'해주세요. algorithm
	std::sort(v.begin(), v.end());
	vector<int>::iterator iter2 = std::unique(v.begin(), v.end());
	v.erase(iter2, v.end());
	// 9. 원소가 11인 원소를 지워주세요. iter, algorithm
	remove(v.begin(), v.end(), 11);
	// 10. 원소가 10보다 작은 원소들을 지워주세요. algorithm
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