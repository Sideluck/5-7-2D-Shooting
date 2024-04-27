#pragma once

class Player
{
public:
	Player() {}
	~Player() {}

	void Init();
	void Update();
	void PlayerAction();
	void Draw();
	void DrawIdle();
	void DrawIdleShot();
	void DrawRun();
	void DrawRunShot();
	void DrawJump();

	void SetIdleTexture(KdTexture* a_tex) { m_IdleTex = a_tex; }
	void SetRunTexture(KdTexture* b_tex) { m_RunTex = b_tex; }
	void SetJumpTexture(KdTexture* c_tex) { m_JumpTex = c_tex; }
	void SetIdleShotTexture(KdTexture* d_tex) { m_IdleShotTex = d_tex; }
	void SetRunShotTexture(KdTexture* e_tex) { m_RunShotTex = e_tex; }

private:

	KdTexture*		m_IdleTex;		//�����p�̃e�N�X�`��
	KdTexture*		m_RunTex;		//����p�̃e�N�X�`��
	KdTexture*		m_JumpTex;		//�W�����v�������̃e�N�X�`��
	KdTexture*		m_IdleShotTex;	//������Ԃŏe�����������̃e�N�X�`��
	KdTexture*		m_RunShotTex;	//�����Ă����Ԃŏe�����������̃e�N�X�`��
	Math::Vector2	m_Pos;			//���W
	Math::Vector2	m_Move;			//�ړ�
	Math::Vector2	m_Image;		//�摜�̑傫��
	Math::Vector2	m_Scale;		//�g���
	Math::Matrix	m_Mat;			//�s��
	Math::Matrix	m_Scalemat;		//�g�k�s��
	Math::Matrix	m_Tansmat;		//�ړ��s��
	float			m_MovePow;		//�ړ���
	float			m_AnimCnt;		//�A�j���[�V�����̃y�[�W
	float			m_AnimSpd;		//�A�j���[�V�����̑��x
	float			m_Gravity;		//�d��
	float			m_JumpPow;		//�W�����v�̍���
	bool			m_AliveFlg;		//�����t���O
	bool			m_JumpFlg;		//�W�����v�������̃t���O
	bool			m_JumpAniFlg;	//�W�����v�̃A�j���[�V�����̃t���O
	bool			m_NotJumpFlg;	//�A���W�����v��h�����߂̃t���O
	bool			m_IdleFlg;		//�������p(�����{�^���������Ă��Ȃ�)���̃t���O
	bool			m_Run_LeftFlg;	//�����Ɉړ����Ă��邩�̃t���O
	bool			m_Run_RightFlg;	//���E�Ɉړ����Ă��邩�̃t���O
	bool			m_GunFlg;	//�e�����������̃t���O
};