#include "BackGround.h"

void BG::Init()
{
	m_Pos = Math::Vector2(0, 0);
	m_Move = Math::Vector2(0, 0);
	m_Image = Math::Vector2(576, 324);
	m_Scale = Math::Vector2(2.5, 2.5);
}

void BG::Update()
{
	m_Scalemat = Math::Matrix::CreateScale(m_Scale.x, m_Scale.y, 0);
	m_Tansmat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_Mat = m_Scalemat * m_Tansmat;
}

void BG::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_BackTex, Math::Rectangle(0, 0, m_Image.x, m_Image.y), 1.0f);
}
