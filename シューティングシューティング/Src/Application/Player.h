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

	KdTexture*		m_IdleTex;		//�����p�̃e�N�X�`��
	KdTexture*		m_RunTex;		//����p�̃e�N�X�`��
	KdTexture*		m_JumpTex;		//�W�����v�������̃e�N�X�`��
	Math::Vector2	m_Pos;			//���W
	Math::Vector2	m_Move;			//�ړ�
	Math::Vector2	m_Image;		//�摜�̑傫��
	Math::Matrix	m_Mat;			//�s��
	Math::Matrix	m_Scalemat;		//�g�k�s��
	Math::Matrix	m_Tansmat;		//�ړ��s��
	float			m_ScaleX;		//���̊g���
	float			m_ScaleY;		//�c�̊g���
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
};