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

	//�C�e���[�^�[
	vector<int>::iterator it;

	it = b.begin();

	//cout << *it << endl;

	it++;

	//cout << *it << endl;

	//40�ǉ�
	//b.push_back(40);

	//�폜
	//b.pop_back();


	system("pause");

	return 0;
}