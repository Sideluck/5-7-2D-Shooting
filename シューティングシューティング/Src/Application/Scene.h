#pragma once

#include "Player.h"
#include "BackGround/BackGround.h"
#include "Object/Bullet.h"

enum SceneType
{
	Title,
	Game,  
	Result 
};

class Scene
{
private:

	Player m_player;
	KdTexture m_playerIdleTex;
	KdTexture m_playerRunTex;
	KdTexture m_playerJumpTex;
	KdTexture m_playerIdleShotTex;
	KdTexture m_playerRunShotTex;
	KdTexture m_BulletTex;

	BG m_back;
	BG m_Gameback;
	BG m_Resultback;
	KdTexture m_TitlebackTex;
	KdTexture m_GamebackTex;
	KdTexture m_ResultbackTex;

	SceneType nowScene;

	bool KeyFlg = false;

public:

	void Init();
	void Release();
	void Update();
	void DynamicDraw2D();
	void Draw2D();

	void DrawTitle();
	void DrawGame();
	void DrawResult();

	void UpdateTitle();
	void UpdateGame();
	void UpdateResult();

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
