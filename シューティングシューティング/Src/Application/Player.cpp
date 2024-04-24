#include "Player.h"

void Player::Init()
{
	m_Pos				= Math::Vector2(0, -200);
	m_Move				= Math::Vector2(0, 0);
	m_Image				= Math::Vector2(48, 48);
	m_AnimCnt			= 0;
	m_AnimSpeed			= 0.13;
	m_MovePow			= 5.0;
	m_ScaleX			= 2.0;
	m_ScaleY			= 2.0;
	m_Gravity			= 0.8;
	m_JumpPow			= 20;
	m_Alive				= true;
	m_Jump				= false;
	m_NotContinuJump    = false;
	m_Idle				= true;
	m_Run_Left			= false;
	m_Run_Right			= false;
}

void Player::Update()
{
	if (!m_Alive)return;
	
	m_Move.x = 0;
	m_Move.y -= m_Gravity;

	PlayerRun();

	m_Scalemat = Math::Matrix::CreateScale(m_ScaleX, m_ScaleY, 0);
	m_Tansmat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_Mat = m_Scalemat * m_Tansmat;
}

void Player::PlayerRun()
{
	//ˆÚ“®

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_Pos.x -= m_MovePow;
		m_ScaleX = -2;
		m_AnimSpeed = 0.2;
		m_Idle = false;
		m_Run_Left = true;
		if (m_Pos.x < -595)
		{
			m_Pos.x = -595;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_Pos.x += m_MovePow;
		m_ScaleX = 2;
		m_AnimSpeed = 0.2;
		m_Idle = false;
		m_Run_Right = true;
		if (m_Pos.x > 595)
		{
			m_Pos.x = 595;
		}
	}
	else
	{
		m_AnimSpeed = 0.13;
		m_Idle = true;
		m_Run_Left = false;
		m_Run_Right = false;
	}

	//ƒWƒƒƒ“ƒv

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (!m_NotContinuJump)
		{
			if (!m_Jump)
			{
				m_Move.y = m_JumpPow;
				m_NotContinuJump = true;
				m_Jump = true;
				m_AnimSpeed = 0.2;
			}
		}
	}
	else 
	{
		m_AnimSpeed = 0.13;
		m_Jump = false;
	}

	m_Pos.x += m_Move.x;
	m_Pos.y += m_Move.y;
	
	if (m_Pos.y < -200)
	{
		m_Pos.y = -200;
		m_Move.y = 0;
		m_NotContinuJump = false;
	}
}

void Player::Draw()
{
	if (!m_Alive)return;

	if (m_Idle && !m_Jump)
	{
		DrawIdle();
	}
	if (m_Run_Left && !m_Jump || m_Run_Right && !m_Jump)
	{
		DrawRun();
	}
	if (m_Jump)
	{
		DrawJump();
	}
}

void Player::DrawIdle()
{
	if (!m_Idle)return;

	m_AnimCnt += m_AnimSpeed;
	if (m_AnimCnt >= 4)
	{
		m_AnimCnt = 0;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_IdleTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}

void Player::DrawRun()
{

	m_AnimCnt += m_AnimSpeed;
	if (m_AnimCnt >= 6)
	{
		m_AnimCnt = 0;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_RunTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}

void Player::DrawJump()
{
	m_AnimCnt += m_AnimSpeed;
	if (m_AnimCnt >= 4)
	{
		m_AnimCnt = 4;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_JumpTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}
