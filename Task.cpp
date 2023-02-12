#include "Task.h"

Task::Task(int id_, Person* person_, std::string name_, std::string contents_, std::string priority_, string deadline_, bool _status)
{
	this->id_ = id_;
	this->name_ = name_;
	this->contents_ = contents_;
	this->priority_ = priority_;
	this->deadline_ = deadline_;
	this->person_ = person_;
}
