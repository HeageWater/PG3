#include "Scene.h"

Scene::Scene(const Scene& obj)
{
	//printf("%s‚ğƒRƒs[‚µ‚Ü‚·",obj.name);
}

Scene* Scene::GetInstance()
{
	static Scene instance;

	return &instance;
}

void Scene::Update()
{

}
