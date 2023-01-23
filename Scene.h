#pragma once

class Scene final {
private:
	Scene();
	~Scene();
	int nowScene;

public:
	static Scene* GetInstance();
	Scene(const Scene& obj) = delete;
	Scene& operator=(const Scene& obj) = delete;

	void ChangeScene(int nextScene);
	int GetnowScene() { return nowScene; };
};
