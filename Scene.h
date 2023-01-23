#pragma once

enum KindScene {
	Title,
	NewGame,
	GamePlay,
	GameClear,
};

class Scene final{
private:
	Scene();
	~Scene();
	Scene(const Scene& obj);

public:
	//Scene(const Scene& obj) = delete;
	//Scene& operater=(const Scene&obj) = delete;

	static Scene* GetInstance();

	int nowScene = Title;
	void ChangeScene();
};
