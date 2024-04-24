#include "Player.h"

void Player::Init()
{
	m_tex.Load("Texture/Player/Player.png");
	m_pos = Math::Vector2(0, 0);
	m_move = Math::Vector2(0, 0);
	m_scaleX = 1.0f;
	m_bAlive = true;
	m_bJump = false;
}

void Player::Update()
{
	if (!m_bAlive)return;
	m_scalemat = Math::Matrix::CreateScale(m_scaleX, 1.0f, 1.0f);
	m_transmat = Math::Matrix::CreateTranslation(0, 0, 0);
	m_mat = m_scalemat * m_transmat;
}

void Player::Draw()
{
	if (!m_bAlive)return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 48, 48), 1.0f);
}
