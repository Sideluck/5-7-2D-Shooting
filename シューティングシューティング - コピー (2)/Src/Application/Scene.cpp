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
	m_back.DrawTitleBack();
}

void Scene::DrawGame()
{
	m_Gameback.DrawGameBack();
	m_player.Draw();
}

void Scene::DrawResult()
{
	m_Resultback.DrawResultBack();
}

void Scene::UpdateTitle()
{
	m_back.UpdateTitleBack();

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
	m_Gameback.UpdateGameBack();
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
	m_Resultback.UpdateResultBack();

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
	m_back.InitTitleBack();
	m_Gameback.InitGameBack();
	m_Resultback.InitResultBack();

	m_playerIdleTex.Load("Texture/Player/Player_Idle.png");
	m_playerRunTex.Load("Texture/Player/Player_Run.png");
	m_playerJumpTex.Load("Texture/Player/Player_Jump.png");
	m_playerIdleShotTex.Load("Texture/Player/Player_Idle_Shot.png");
	m_playerRunShotTex.Load("Texture/Player/Player_Run_Shot.png");
	m_BulletTex.Load("Texture/Object/Bullet.png");
	m_TitlebackTex.Load("Texture/BackGround/Background.png");
	m_GamebackTex.Load("Texture/BackGround/Background2.png");
	m_ResultbackTex.Load("Texture/BackGround/Background3.png");

	m_player.SetIdleTexture(&m_playerIdleTex);
	m_player.SetRunTexture(&m_playerRunTex);
	m_player.SetJumpTexture(&m_playerJumpTex);
	m_player.SetIdleShotTexture(&m_playerIdleShotTex);
	m_player.SetRunShotTexture(&m_playerRunShotTex);
	m_player.SetBulletTexture(&m_BulletTex);
	m_back.SetTitleBackTexture(&m_TitlebackTex);
	m_Gameback.SetGameBackTexture(&m_GamebackTex);
	m_Resultback.SetResultBackTexture(&m_ResultbackTex);

}

void Scene::Release()
{
	m_playerIdleTex.Release();
	m_playerRunTex.Release();
	m_playerJumpTex.Release();
	m_playerIdleShotTex.Release();
	m_playerRunShotTex.Release();
	m_TitlebackTex.Release();
	m_GamebackTex.Release();
}

void Scene::ImGuiUpdate()
{
	//return;


	float p = m_player.GetPos().x;

	ImGui::SliderFloat(u8"炎CD",&p, 0, 100);

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
