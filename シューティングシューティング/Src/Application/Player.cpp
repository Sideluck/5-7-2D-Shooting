#include "Player.h"

void Player::Init()
{
	m_Pos				= Math::Vector2(0, -200);
	m_Move				= Math::Vector2(0, 0);
	m_Image				= Math::Vector2(48, 48);
	m_Scale		        = Math::Vector2(2.5, 2.5);
	m_AnimCnt			= 0;
	m_AnimSpd			= 0;
	m_MovePow			= 5.0;
	m_Gravity			= 0.8;
	m_JumpPow			= 15;
	m_AliveFlg			= true;
	m_JumpFlg			= false;
	m_JumpAniFlg		= false;
	m_NotJumpFlg		= false;
	m_IdleFlg			= true;
	m_IdleLeftFlg		= false;
	m_IdleRightFlg		= true;
	m_Run_LeftFlg		= false;
	m_Run_RightFlg		= false;
}

void Player::Update()
{
	if (!m_AliveFlg)return;
	
	m_Move.x = 0;
	m_Move.y -= m_Gravity;

	PlayerAction();

	m_Scalemat = Math::Matrix::CreateScale(m_Scale.x, m_Scale.y, 0);
	m_Tansmat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	m_Mat = m_Scalemat * m_Tansmat;
}

void Player::PlayerAction()
{
	//ˆÚ“®

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_Pos.x -= m_MovePow;
		m_Scale.x = -2.5;
		m_IdleFlg = false;
		m_Run_LeftFlg = true;
		m_Run_RightFlg = false;
		m_IdleLeftFlg = true;
		m_IdleRightFlg = false;
		if (m_Pos.x < -595)
		{
			m_Pos.x = -595;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_Pos.x += m_MovePow;
		m_Scale.x = 2.5;
		m_IdleFlg = false;
		m_Run_LeftFlg = false;
		m_Run_RightFlg = true;
		m_IdleLeftFlg = false;
		m_IdleRightFlg = true;
		if (m_Pos.x > 595)
		{
			m_Pos.x = 595;
		}
	}
	else
	{
		m_IdleFlg = true;
		m_Run_LeftFlg = false;
		m_Run_RightFlg = false;
	}

	//ƒWƒƒƒ“ƒv

	if (m_Pos.y > -200)
	{
		m_JumpAniFlg = true;
	}
	else {
		m_JumpAniFlg = false;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (!m_JumpAniFlg)
		{
			if (!m_NotJumpFlg)
			{
				if (!m_JumpFlg)
				{
					m_Move.y = m_JumpPow;
					m_JumpFlg = true;
					m_NotJumpFlg = true;
				}
			}
		}
	}
	else 
	{
		m_JumpFlg = false;
	}

	m_Pos.x += m_Move.x;
	m_Pos.y += m_Move.y;
	
	if (m_Pos.y < -200)
	{
		m_Pos.y = -200;
		m_Move.y = 0;
		m_NotJumpFlg = false;
	}

	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		m_GunFlg = true;
		if (m_Run_RightFlg|| m_IdleRightFlg)
		{
			for (int b = 0; b < RIGHTBULLET_MAX; b++)
			{
				if (m_RightbulletList[b] == nullptr)
				{

					m_RightbulletList[b] = new Bullet();
					m_RightbulletList[b]->InitRightBullet();
					m_RightbulletList[b]->SetRightBulletTexture(m_RightBulletTex);
					m_RightbulletList[b]->ShotRightBullet(m_Pos);
					break;
				}
			}
		}	
		if (m_Run_LeftFlg|| m_IdleLeftFlg)
		{
			for (int b = 0; b < LEFTBULLET_MAX; b++)
			{
				if (m_LeftbulletList[b] == nullptr)
				{
					m_LeftbulletList[b] = new Bullet();
					m_LeftbulletList[b]->InitLeftBullet();
					m_LeftbulletList[b]->SetLeftBulletTexture(m_LeftBulletTex);
					m_LeftbulletList[b]->ShotLeftBullet(m_Pos);
					break;
				}
			}
		}
	}
	else
	{
		m_GunFlg = false;
	}


	for (int b = 0; b < RIGHTBULLET_MAX; b++)
	{
		if (m_RightbulletList[b] == nullptr)continue;
		m_RightbulletList[b]->UpdateRightBullet();

		if (!m_RightbulletList[b]->GetAlive())
		{
			delete m_RightbulletList[b];
			m_RightbulletList[b] = nullptr;
		}
	}

	for (int b = 0; b < LEFTBULLET_MAX; b++)
	{
		if (m_LeftbulletList[b] == nullptr)continue;
		m_LeftbulletList[b]->UpdateLeftBullet();

		if (!m_LeftbulletList[b]->GetAlive())
		{
			delete m_LeftbulletList[b];
			m_LeftbulletList[b] = nullptr;
		}
	}
}

void Player::Draw()
{
	if (!m_AliveFlg)return;

	DrawRightBullet();
	DrawLeftBullet();

	if (m_IdleFlg && !m_JumpAniFlg && !m_GunFlg)
	{
		DrawIdle();
	}
	if (m_Run_LeftFlg && !m_JumpAniFlg && !m_GunFlg || m_Run_RightFlg && !m_JumpAniFlg && !m_GunFlg)
	{
		DrawRun();
	}
	if (m_JumpAniFlg)
	{
		DrawJump();
	}
	if (m_IdleFlg && !m_JumpAniFlg && m_GunFlg)
	{
		DrawIdleShot();
	}
	if (m_Run_LeftFlg && !m_JumpAniFlg && m_GunFlg || m_Run_RightFlg && !m_JumpAniFlg && m_GunFlg)
	{
		DrawRunShot();
	}
}

void Player::DrawRightBullet()
{
	for (int b = 0; b < RIGHTBULLET_MAX; b++)
	{
		if (m_RightbulletList[b] == nullptr)continue;
		m_RightbulletList[b]->DrawRightBullet();
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_RightBulletTex, Math::Rectangle(0, 0, 0, 0), 1.0f);
}

void Player::DrawLeftBullet()
{
	for (int b = 0; b < LEFTBULLET_MAX; b++)
	{
		if (m_LeftbulletList[b] == nullptr)continue;
		m_LeftbulletList[b]->DrawLeftBullet();
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_LeftBulletTex, Math::Rectangle(0, 0, 0, 0), 1.0f);
}

void Player::DrawIdle()
{
	if (!m_IdleFlg)return;

	m_AnimSpd = 0.13;
	m_AnimCnt += m_AnimSpd;
	if (m_AnimCnt >= 4)
	{
		m_AnimCnt = 0;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_IdleTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}

void Player::DrawIdleShot()
{
	m_AnimSpd = 0.2;
	m_AnimCnt += m_AnimSpd;
	if (m_AnimCnt >= 2)
	{
		m_AnimCnt = 0;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_IdleShotTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}

void Player::DrawRun()
{
	m_AnimSpd = 0.25;
	m_AnimCnt += m_AnimSpd;
	if (m_AnimCnt >= 6)
	{
		m_AnimCnt = 0;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_RunTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}

void Player::DrawRunShot()
{
	m_AnimSpd = 0.25;
	m_AnimCnt += m_AnimSpd;
	if (m_AnimCnt >= 6)
	{
		m_AnimCnt = 0;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_RunShotTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}

void Player::DrawJump()
{
	m_AnimCnt += m_AnimSpd;
	if (m_AnimCnt >= 1)
	{
		m_AnimCnt = 1;
	}

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_JumpTex, Math::Rectangle((int)m_AnimCnt * m_Image.x, 0, m_Image.x, m_Image.y), 1.0f);
}
