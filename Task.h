#pragma once
#include <string>
#include <iostream>
#include "Person.h"
using namespace std;

class Task
{
public:
	Task(int id_, string title_, string contents_,
		string priority_, string deadline_, Person* person_);

	Task(int id_, Person* person_, std::string name_, std::string contents_, 
		std::string priority_, string deadline_, bool _status);

	int id_;
	Person* person_;
	string name_;
	string contents_;
	string priority_;
	string deadline_;
	bool status_;
};