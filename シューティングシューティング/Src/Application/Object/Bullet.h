#pragma once

class Bullet
{
public:
	Bullet(){}
	~Bullet(){}

	void InitLeftBullet();
	void UpdateLeftBullet();
	void DrawLeftBullet();
	void ShotLeftBullet(Math::Vector2 a_shotPos);

	void InitRightBullet();
	void UpdateRightBullet();
	void DrawRightBullet();
	void ShotRightBullet(Math::Vector2 a_shotPos);
	
	const bool GetAlive() { return m_AliveFlg; }
	const Math::Vector2 GetPos() { return m_Pos; }

	void SetLeftBulletTexture(KdTexture* b_tex) { m_LeftBulletTex = b_tex; }
	void SetRightBulletTexture(KdTexture* a_tex) { m_RightBulletTex = a_tex; }

private:

	KdTexture*		m_RightBulletTex;	//�e�̃e�N�X�`��(�E)
	KdTexture*		m_LeftBulletTex;	//�e�̃e�N�X�`��(��)
	Math::Vector2	m_Pos;				//���W
	Math::Vector2	m_Move;				//�ړ�
	Math::Vector2	m_Image;			//�摜�̑傫��
	Math::Vector2	m_Scale;			//�g���
	Math::Matrix	m_Mat;				//�s��
	Math::Matrix	m_Scalemat;			//�g�k�s��
	Math::Matrix	m_Tansmat;			//�ړ��s��
	float			m_MovePow;			//�ړ���
	bool			m_AliveFlg;			//�����t���O
	bool			m_FireFlg;			//�e���˃t���O
};