#include "Bullet.h"
#include "../Utility.h"

void Bullet::Init()
{
	srand(timeGetTime());

	m_Pos		= Math::Vector2(0, -1000);
	m_Move		= Math::Vector2(0, 0);
	m_Image		= Math::Vector2(4, 4);
	m_Scale		= Math::Vector2(2.5, 2.5);
	m_MovePow	= 15.0;
	m_AliveFlg	= false;
}

void Bullet::Update()
{
	m_Pos.x += m_MovePow + rand() % 3 - 1;

	if (m_Pos.x < -Screen::HalfWidth|| m_Pos.x > Screen::HalfWidth
		|| m_Pos.y < -Screen::HalfHeight|| m_Pos.y > Screen::HalfHeight)
	{
		m_AliveFlg = false;
	}

	m_Scalemat = Math::Matrix::CreateScale(m_Scale.x, m_Scale.y, 0);
	m_Tansmat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_Mat = m_Scalemat * m_Tansmat;
}

void Bullet::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_BulletTex, Math::Rectangle(0, 0, m_Image.x, m_Image.y), 1.0f);
}

void Bullet::Shot(Math::Vector2 a_shotPos)
{
	m_AliveFlg = true;   
	m_Pos = a_shotPos;
}
