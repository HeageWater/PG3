#include "PersonManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

PersonManager* PersonManager::GetInstance()
{
	static PersonManager instance;
	return &instance;
}

void PersonManager::PrintAllId()
{
	for (auto& itr : person)
	{
		cout << "ID:" << itr->id_ << "’S“–ŽÒ–¼:" << itr->name_ << endl;
	}
}

void PersonManager::ReadTxt()
{
	ofstream file;
	file.open("Data\\person.txt", std::ios::out);

	if (file.fail())
	{
		return;
	}

	for (auto& itr : person)
	{
		if (this == nullptr)
		{
			file << "ID" << " " << -1 << endl;
		}
		else
		{
			file << "ID" << " " << itr->id_ << endl;
		}

		if (this == nullptr)
		{
			file << "Name" << " " << "NULL" << endl;
		}
		else
		{
			file << "Name" << " " << itr->name_ << endl;
		}

		if (this == nullptr)
		{
			file << "Class" << " " << "NULL" << endl;
		}
		else
		{
			file << "Class" << " " << itr->class_ << endl;
		}

		file << "End" << " " << endl;
		file << endl;
	}

	file << "EOF" << endl;
	file.close();
}

void PersonManager::WriteTxt()
{
	unsigned int id;
	std::string name;
	std::string className;
	ifstream file;
	file.open("Data\\person.txt", std::ios::in);

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
		else if (key == "ClassName")
		{
			line_stream >> className;
		}
		else if (key == "End")
		{
			AddPIC(id, name, className);
		}
	}

	file.close();
}

Person* PersonManager::GetPicPtr(unsigned int id)
{
	Person* ptr;
	for (auto& itr : person)
	{
		if (itr->id_ == id)
		{
			ptr = itr.get();
			return ptr;
		}
	}
	cout << "PIC::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
	return nullptr;
}

unsigned int PersonManager::AddPIC(std::string name, std::string className)
{
	int id = 1;
	for (unsigned int i = 0; i < person.size(); i++)
	{
		bool success = true;//id‚ª”í‚Á‚Ä–³‚¯‚ê‚ÎtrueA”í‚Á‚½‚çfalse
		id++;
		for (auto& itr : person)
		{
			if (itr->id_ == id)
			{
				success = false;
				break;
			}
		}
		if (success)
		{
			unique_ptr<Person> temp = make_unique<Person>(id, name, className);
			person.push_back(move(temp));
			return id;
		}

	}
	if (person.size() == 0)
	{
		int id = 1;
		unique_ptr<Person> temp = make_unique<Person>(id, name, className);
		person.push_back(move(temp));
		return id;
	}
	return -1;
}

unsigned int PersonManager::AddPIC(unsigned int id, std::string name, std::string className)
{
	unique_ptr<Person> temp = make_unique<Person>(id, name, className);
	person.push_back(move(temp));
	return id;
}

void PersonManager::SetName(unsigned int id, std::string _name)
{
	for (auto& itr : person)
	{
		if (itr->id_ == id)
		{
			itr->name_ = _name;
			return;
		}
	}
	cout << "PIC::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void PersonManager::SetClass(unsigned int id, std::string _class)
{
	for (auto& itr : person)
	{
		if (itr->id_ == id)
		{
			itr->class_ = _class;
			return;
		}
	}
	cout << "PIC::ŠY“–‚ÌId‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
}

void PersonManager::DeletePic(unsigned int id)
{
	person.remove_if([=](auto& itr) {return itr->id_ == id; });
}
