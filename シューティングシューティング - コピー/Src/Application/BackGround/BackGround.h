#pragma once
class BG
{
public:
	BG(){}
	~BG(){}

	void Init();
	void Update();
	void Draw();

	void SetBackTexture(KdTexture* a_tex) { m_BackTex = a_tex; }

private:
	KdTexture*		m_BackTex;		//�w�i�e�N�X�`��
	Math::Vector2	m_Pos;			//���W
	Math::Vector2	m_Move;			//�ړ�
	Math::Vector2	m_Image;		//�摜�̑傫��
	Math::Vector2	m_Scale;		//�g���
	Math::Matrix	m_Mat;			//�s��
	Math::Matrix	m_Scalemat;		//�g�k�s��
	Math::Matrix	m_Tansmat;		//�ړ��s��
	float			m_MovePow;		//�ړ���
};