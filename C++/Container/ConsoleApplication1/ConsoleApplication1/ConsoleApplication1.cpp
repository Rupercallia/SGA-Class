#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


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

	iter = std::find(v.begin(), v.end(), 1);
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

	struct Under_50
	{
		bool operator()(int value)
		{
			if (value < Num)
				return true;
			return false;
		}

		int Num;
	};

	Under_50 under_50;
	under_50.Num = 50;
	bool is_under_50 = all_of(v.begin(), v.end(), under_50);

	if (is_under_50)
	{
		cout << "2" << endl;
	}
	else
	{
		cout << "3" << endl;
	}

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (under_50(*iter))
		{
			is_under_50 = true;
			break;
		}
	}


	// 4. 하나라도 30보다 큰 수가 있는지 bool으로 알려주세요. (iter, algorithm)

	struct Over_30
	{
		bool operator()(int value)
		{
			if (value > Num)
				return true;
			return false;
		}

		int Num;
	};

	Over_30 over_30;
	over_30.Num = 30;
	bool is_over_30 = any_of(v.begin(), v.end(), over_30);

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (over_30(*iter))
		{
			is_over_30 = true;
			break;
		}
	}
	

	// 5. 원소가 3인 원소들의 개수를 알려주세요. algorithm

	struct Just_3
	{
		bool operator()(int value)
		{
			if (value == Num)
				return true;
			return false;
		}

		int Num;
	};

	Just_3 just_3;
	just_3.Num = 3;

	int count_3 = count_if(v.begin(), v.end(), just_3);

	int iter_count_just_3 = 0;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (just_3(*iter))
		{
			iter_count_just_3++;
		}
	}
	

	// 6. 원소가 5보다 큰 원소들의 개수를 알려주세요. algorithm

	struct Over_5
	{
		bool operator()(int value)
		{
			if (value > Num)
				return true;
			return false;
		}

		int Num;
	};

	Over_5 over_5;
	over_5.Num = 5;
	int count_over_5 = count_if(v.begin(), v.end(), over_5);

	int iter_count_over_5 = 0;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (over_5(*iter))
		{
			iter_count_over_5++;
		}
	}

	// 7. 모든 원소에 3을 곱해주세요. algorithm

	struct Gob3
	{
		bool operator()(int &value)
		{
			value *= 3;
			return true;
		}

	};

	Gob3 gob3;
	for_each(v.begin(), v.end(),gob3);

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (gob3(*iter))
		{
			break;
		}
	}

	//다시 나누기

	struct Nanu3
	{
		bool operator()(int& value)
		{
			value /= 3;
			return true;
		}

	};

	Nanu3 nanu3;
	for_each(v.begin(), v.end(), nanu3);

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (nanu3(*iter))
		{
			break;
		}
	}

	// 8. 중복된 원소들을 '제거'해주세요. algorithm

	std::sort(v.begin(), v.end());
	vector<int>::iterator iter2 = std::unique(v.begin(), v.end());
	v.erase(iter2, v.end());

	// 9. 원소가 11인 원소를 지워주세요. iter, algorithm

	struct Erase_11
	{
		bool operator()(const int& value)
		{
			if (value == Num)
				return true;
			return false;
		}

		int Num;
	};

	Erase_11 erase_11;
	erase_11.Num = 11;
	v.erase(remove_if(v.begin(), v.end(), erase_11), v.end());

	iter = v.begin();

	for (iter; iter != v.end(); )
	{
		if (*iter == 11) // 조건을 수정합니다
		{
			iter = v.erase(iter);
			continue;
		}

		iter++;
	}

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
		if (*iter < 10)
		{
			iter = v.erase(iter);
			continue;
		}

		iter++;
	}

  

    return 0;
}
