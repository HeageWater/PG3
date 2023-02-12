#pragma once

struct Person
{
	int id_;
	int name_;
	int class_;
};

class Task
{
	//int id_;
	 Person person_;
	//int class_;
	int title_;
	int contents_;
	int priority_;
	int deadline_;
	int status_;
};