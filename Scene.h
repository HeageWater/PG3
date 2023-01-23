#pragma once

class Scene final {
private:
	Scene();
	~Scene();
	int nowScene;

public:
	static Scene* GetInstance();

	void ChangeScene(int nextScene);
	int GetnowScene() { return nowScene; };
};
