#include "Player.h"

void Player::Init()
{
	m_pos = Math::Vector2(0, 0);
	m_move = Math::Vector2(0, 0);
	m_scale = Math::Vector2(2, 2);
	m_image = Math::Vector2(48, 48);
	m_AnimCnt = 0;
	m_AnimSpeed = 0.13;
	MovePow = 3.0;
	m_bAlive = true;
	m_bJump = false;
	m_Idle = true;
}

void Player::Update()
{
	if (!m_bAlive)return;

	m_AnimCnt += m_AnimSpeed;
	if (m_Idle && m_AnimCnt >= 4)
	{
		m_AnimCnt = 0;
	}

	m_scalemat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transmat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scalemat * m_transmat;
}

void Player::Draw()
{
	if (m_Idle)
	{
		DrawIdle();
	}
}

void Player::DrawIdle()
{
	if (!m_bAlive)return;
	if (!m_Idle)return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle((int)m_AnimCnt * m_image.x, 0, m_image.x, m_image.y), 1.0f);
}
