#include "stdio.h"
#include "stdlib.h"
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;

int main() {

	list<int> lst;
	//std::list<int> lst;

	vector<int> b = {1,2,3};

	//イテレーター
	vector<int>::iterator it;

	it = b.begin();

	//cout << *it << endl;

	it++;

	//cout << *it << endl;

	//40追加
	//b.push_back(40);

	//削除
	//b.pop_back();


	system("pause");

	return 0;
}