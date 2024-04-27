#include "BackGround.h"

void BG::InitTitleBack()
{
	m_Pos = Math::Vector2(0, 0);
	m_Move = Math::Vector2(0, 0);
	m_Image = Math::Vector2(576, 324);
	m_Scale = Math::Vector2(2.5, 2.5);
}

void BG::UpdateTitleBack()
{
	m_Scalemat = Math::Matrix::CreateScale(m_Scale.x, m_Scale.y, 0);
	m_Tansmat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_Mat = m_Scalemat * m_Tansmat;
}

void BG::DrawTitleBack()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_TitleBackTex, Math::Rectangle(0, 0, m_Image.x, m_Image.y), 1.0f);
}

void BG::InitGameBack()
{
	m_Pos = Math::Vector2(0, 0);
	m_Move = Math::Vector2(0, 0);
	m_Image = Math::Vector2(576, 324);
	m_Scale = Math::Vector2(2.5, 2.5);
}

void BG::UpdateGameBack()
{
	m_Scalemat = Math::Matrix::CreateScale(m_Scale.x, m_Scale.y, 0);
	m_Tansmat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_Mat = m_Scalemat * m_Tansmat;
}

void BG::DrawGameBack()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_GameBackTex, Math::Rectangle(0, 0, m_Image.x, m_Image.y), 1.0f);
}

void BG::InitResultBack()
{
	m_Pos = Math::Vector2(0, 0);
	m_Move = Math::Vector2(0, 0);
	m_Image = Math::Vector2(5826, 2584);
	m_Scale = Math::Vector2(0.3, 0.3);
}

void BG::UpdateResultBack()
{
	m_Scalemat = Math::Matrix::CreateScale(m_Scale.x, m_Scale.y, 0);
	m_Tansmat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_Mat = m_Scalemat * m_Tansmat;
}

void BG::DrawResultBack()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_ResultBackTex, Math::Rectangle(0, 0, m_Image.x, m_Image.y), 1.0f);
}
