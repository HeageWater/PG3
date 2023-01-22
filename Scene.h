#pragma once

class Scene final{
private:
	Scene();
	~Scene();
	Scene(const Scene& obj);

public:
	Scene(const Scene& obj) = delete;
	//Scene& operater=(const Scene&obj) = delete;

	static Scene* GetInstance();

	void Update();
};
