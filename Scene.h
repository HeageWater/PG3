#pragma once
#include "PersonManager.h"
#include "TaskManager.h"
#include <memory>
#include <list>

class Scene
{
private:
	Scene() {};
	~Scene() {};
	PersonManager* picManager = PersonManager::GetInstance();
	TaskManager* taskManager = TaskManager::GetInstance();

	void Initialize();
	void Update();
	void End();
public:

	Scene(const Scene& manager) = delete;
	Scene& operator= (const Scene& manager) = delete;
	static Scene* GetInstance();
	void Act();
};