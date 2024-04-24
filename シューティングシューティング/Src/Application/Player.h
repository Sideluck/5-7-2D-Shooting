#pragma once

class Player
{
public:
	Player() {};
	~Player() {};

	void Init();
	void Update();
	void PlayerRun();
	void Draw();
	void DrawIdle();
	void DrawRun();
	void DrawJump();

	void IdleSetTexture(KdTexture* a_tex) { m_IdleTex = a_tex; }
	void RunSetTexture(KdTexture* b_tex) { m_RunTex = b_tex; }
	void JumpSetTexture(KdTexture* c_tex) { m_JumpTex = c_tex; }

private:

	KdTexture*		m_IdleTex;
	KdTexture*		m_RunTex;
	KdTexture*		m_JumpTex;
	Math::Vector2	m_Pos;
	Math::Vector2	m_Move;
	Math::Vector2	m_Image;
	Math::Matrix	m_Mat;
	Math::Matrix	m_Scalemat;
	Math::Matrix	m_Tansmat;
	float			m_ScaleX;
	float			m_ScaleY;
	float			m_MovePow;
	float			m_AnimCnt;
	float			m_AnimSpeed;
	float			m_Gravity;
	float			m_JumpPow;
	bool			m_Alive;
	bool			m_Jump;
	bool			m_NotContinuJump;
	bool			m_Idle;
	bool			m_Run_Left;
	bool			m_Run_Right;
};