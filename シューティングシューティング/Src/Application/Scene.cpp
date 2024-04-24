#include "main.h"
#include "Scene.h"

void Scene::DynamicDraw2D()
{
}

void Scene::Draw2D()
{
	m_player.Draw();
}

void Scene::Update()
{
	m_player.Update();
}

void Scene::Init()
{
	m_player.Init();

	m_playerIdleTex.Load("Texture/Player/Player_Idle.png");
	m_playerRunTex.Load("Texture/Player/Player_Run.png");
	m_playerJumpTex.Load("Texture/Player/Player_Jump.png");

	m_player.IdleSetTexture(&m_playerIdleTex);
	m_player.RunSetTexture(&m_playerRunTex);
	m_player.JumpSetTexture(&m_playerJumpTex);

}

void Scene::Release()
{
	m_playerIdleTex.Release();
	m_playerRunTex.Release();
	m_playerJumpTex.Release();
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
