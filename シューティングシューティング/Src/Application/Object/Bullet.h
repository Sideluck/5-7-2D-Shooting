#pragma once

class Bullet
{
public:
	Bullet(){}
	~Bullet(){}

	void Init();
	void Update();
	void Draw();
	void Shot(Math::Vector2 a_shotPos);//���ˑ��x

	const bool GetAlive() { return m_AliveFlg; }
	const Math::Vector2 GetPos() { return m_Pos; }

	void SetBulletTexture(KdTexture* a_tex) { m_BulletTex = a_tex; }

private:

	KdTexture*		m_BulletTex;	//�e�̃e�N�X�`��
	Math::Vector2	m_Pos;			//���W
	Math::Vector2	m_Move;			//�ړ�
	Math::Vector2	m_Image;		//�摜�̑傫��
	Math::Vector2	m_Scale;		//�g���
	Math::Matrix	m_Mat;			//�s��
	Math::Matrix	m_Scalemat;		//�g�k�s��
	Math::Matrix	m_Tansmat;		//�ړ��s��
	float			m_MovePow;		//�ړ���
	bool			m_AliveFlg;		//�����t���O
	bool			m_FireFlg;		//�e���˃t���O
};