#pragma once
#include "Task.h"
#include "PersonManager.h"
#include <list>
#include <memory>
class TaskManager
{
private:
	TaskManager() {};
	~TaskManager() {};
	PersonManager* picManager = PersonManager::GetInstance();
	std::list<std::unique_ptr<Task>> tasks;

public:
	TaskManager(const TaskManager& manager) = delete;
	TaskManager& operator= (const TaskManager& manager) = delete;
	static TaskManager* GetInstance();

	Task* GetTask(unsigned int id);

	int AddTask(int picId, std::string name,
		std::string content, std::string priority, string deadline, bool status);
	int AddTask(int id, int picId, std::string name,
		std::string content, std::string priority, string deadline, bool status);//id手動設定用(ロード時に使用する)
	void DeleteTask(int id);
	void PrintAllId();
	void SetPic(int id, Person* pic);
	void SetStatus(int id, bool status);
	void SetPriority(int id, std::string priority);
	void SetContent(int id, std::string content);
	void SetDate(int id, string deadline);
	void OutPut();
	void InPut();
};