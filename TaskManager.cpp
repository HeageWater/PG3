#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

TaskManager* TaskManager::GetInstance()
{
	static TaskManager instance;
	return &instance;
}

Task* TaskManager::GetTask(unsigned int id)
{
	Task* ptr;
	for (auto& itr : tasks)
	{
		if (itr->id_ == id)
		{
			ptr = itr.get();
			return ptr;
		}
	}
	cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
	return nullptr;
}

int TaskManager::AddTask(int picId, std::string name, std::string content, std::string priority, string deadline, bool status)
{
	int id = 1;
	for (unsigned int i = 0; i < tasks.size(); i++)
	{
		bool success = true;
		id++;
		for (auto& itr : tasks)
		{
			if (itr->id_ == id)
			{
				success = false;
				break;
			}
		}
		if (success)
		{
			unique_ptr<Task> temp = make_unique<Task>(id, picManager->GetPicPtr(picId), name, content, priority, deadline, status);
			tasks.push_back(move(temp));
			return id;
		}

	}
	if (tasks.size() == 0)
	{
		int id = 1;
		unique_ptr<Task> temp = make_unique<Task>(id, picManager->GetPicPtr(picId), name, content, priority, deadline, status);
		tasks.push_back(move(temp));
		return id;
	}
	return -1;
}

int TaskManager::AddTask(int id, int picId, std::string name, std::string content, std::string priority, string deadline, bool status)
{
	unique_ptr<Task> temp = make_unique<Task>(id, picManager->GetPicPtr(picId), name, content, priority, deadline, status);
	tasks.push_back(move(temp));
	return id;
}

void TaskManager::DeleteTask(int id)
{
	tasks.remove_if([=](auto& itr) {return itr->id_ == id; });
}

void TaskManager::PrintAllId()
{
	for (auto& itr : tasks)
	{
		cout << "ID:" << itr->id_ << "ƒ^ƒXƒN–¼:" << itr->person_->name_ << endl;
	}

}

void TaskManager::SetPic(int id, Person* pic)
{
	for (auto& itr : tasks)
	{
		if (itr->id_ == id)
		{
			itr->person_ = pic;
			return;
		}
	}
	cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::SetStatus(int id, bool status)
{
	for (auto& itr : tasks)
	{
		if (itr->id_ == id)
		{
			itr->status_ = status;
			return;
		}
	}
	cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::SetPriority(int id, std::string priority)
{
	for (auto& itr : tasks)
	{
		if (itr->id_ == id)
		{
			itr->priority_ = priority;
			return;
		}
	}
	cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::SetContent(int id, std::string content)
{
	for (auto& itr : tasks)
	{
		if (itr->id_ == id)
		{
			itr->contents_ = content;
			return;
		}
	}
	cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::SetDate(int id, string deadline)
{
	for (auto& itr : tasks)
	{
		if (itr->id_ == id)
		{
			itr->deadline_ = deadline;
			return;
		}
	}
	cout << "Task::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void TaskManager::OutPut()
{
	ofstream file;
	file.open("Data\\task.txt", std::ios::out);
	if (file.fail())
	{
		return;
	}
	for (auto& itr : tasks)
	{
		file << "ID" << " " << itr->id_ << endl;
		file << "Name" << " " << itr->person_->name_ << endl;
		file << "Content" << " " << itr->contents_ << endl;
		file << "Priority" << " " << itr->priority_ << endl;
		file << "Status" << " " << itr->status_ << endl;

		if (itr->person_)
		{
			file << "PicID" << " " << itr->person_->id_ << endl;
		}
		else
		{
			file << "PicID" << " " << -1 << endl;
		}
		file << "DeadLineMonth" << " " << itr->deadline_ << endl;
		file << "End" << " " << endl;
		file << endl;
	}
	file << "EOF" << endl;
	file.close();
}

void TaskManager::InPut()
{
	int id;
	int pic;
	std::string name;
	std::string content;
	std::string priority;
	std::string deadline;
	bool status;
	ifstream file;

	file.open("Data\\task.txt", std::ios::in);

	if (file.fail())
	{
		return;
	}

	string line;

	while (getline(file, line))
	{
		std::istringstream line_stream(line);
		string key;
		getline(line_stream, key, ' ');

		if (key == "ID")
		{
			line_stream >> id;
		}
		else if (key == "Name")
		{
			line_stream >> name;
		}
		else if (key == "Content")
		{
			line_stream >> content;
		}
		else if (key == "Priority")
		{
			line_stream >> priority;
		}
		else if (key == "Status")
		{
			line_stream >> status;
		}
		else if (key == "PicID")
		{
			line_stream >> pic;
		}
		else if (key == "DeadLineMonth")
		{
			line_stream >> deadline;
		}
		else if (key == "End")
		{
			AddTask(id, pic, name, content, priority, deadline, status);
		}
	}

	file.close();
}
