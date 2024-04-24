#pragma once

#include "Player.h"

class Scene
{
private:

	Player m_player;
	KdTexture m_playerTex;

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
