#include "main.h"
#include "Scene.h"

void Scene::DynamicDraw2D()
{
}

void Scene::Draw2D()
{
	switch (nowScene)
	{
	case SceneType::Title:
		DrawTitle();
		break;
	case SceneType::Game:
		DrawGame();
		break;
	case SceneType::Result:
		DrawResult();
		break;
	default:
		break;
	}
	
}


void Scene::Update()
{
	switch (nowScene) {
	case SceneType::Title:
		UpdateTitle();
		break;
	case SceneType::Game:
		UpdateGame();
		break;
	case SceneType::Result:
		UpdateResult();
		break;
	default:
		break;
	}
	
}

void Scene::DrawTitle()
{
	m_back.Draw();
}

void Scene::DrawGame()
{
	m_player.Draw();
}

void Scene::DrawResult()
{

}

void Scene::UpdateTitle()
{
	m_back.Update();

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!KeyFlg)
		{
			KeyFlg = true;
			nowScene = Game;
		}
	}
	else 
	{
		KeyFlg = false;
	}
}

void Scene::UpdateGame()
{
	m_player.Update();

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!KeyFlg)
		{
			KeyFlg = true;
			nowScene = Result;
		}
	}
	else
	{
		KeyFlg = false;
	}
}

void Scene::UpdateResult()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!KeyFlg)
		{
			KeyFlg = true;
			nowScene = Title;
		}
	}
	else
	{
		KeyFlg = false;
	}
}


void Scene::Init()
{
	nowScene = Title;

	m_player.Init();
	m_back.Init();

	m_playerIdleTex.Load("Texture/Player/Player_Idle.png");
	m_playerRunTex.Load("Texture/Player/Player_Run.png");
	m_playerJumpTex.Load("Texture/Player/Player_Jump.png");
	m_playerIdleShotTex.Load("Texture/Player/Player_Idle_Shot.png");
	m_playerRunShotTex.Load("Texture/Player/Player_Run_Shot.png");
	m_backTex.Load("Texture/BackGround/BackGround.png");

	m_player.SetIdleTexture(&m_playerIdleTex);
	m_player.SetRunTexture(&m_playerRunTex);
	m_player.SetJumpTexture(&m_playerJumpTex);
	m_player.SetIdleShotTexture(&m_playerIdleShotTex);
	m_player.SetRunShotTexture(&m_playerRunShotTex);
	m_back.SetBackTexture(&m_backTex);

}

void Scene::Release()
{
	m_playerIdleTex.Release();
	m_playerRunTex.Release();
	m_playerJumpTex.Release();
	m_playerIdleShotTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
