#include "Scene.h"

Scene::~Scene()
{
}

Scene::Scene()
{
	//printf("%s���R�s�[���܂�",obj.name);

	//x = obj.x;
}

Scene* Scene::GetInstance()
{
	static Scene instance;

	return &instance;
}

void Scene::ChangeScene()
{

}
