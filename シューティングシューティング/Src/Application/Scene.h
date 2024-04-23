#pragma once

class Scene
{
private:

public:

	void Init();

	void Release();

	void Update();

	void DynamicDraw2D();

	void Draw2D();

	// GUIèàóù
	void ImGuiUpdate();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
