#pragma once
class BG
{
public:
	BG(){}
	~BG(){}

	//�^�C�g����ʂ̔w�i
	void InitTitleBack();
	void UpdateTitleBack();
	void DrawTitleBack();
	
	//�Q�[����ʂ̔w�i
	void InitGameBack();
	void UpdateGameBack();
	void DrawGameBack();

	//���U���g��ʂ̔w�i
	void InitResultBack();
	void UpdateResultBack();
	void DrawResultBack();

	void SetTitleBackTexture(KdTexture* a_tex) { m_TitleBackTex = a_tex; }
	void SetGameBackTexture(KdTexture* b_tex) { m_GameBackTex = b_tex; }
	void SetResultBackTexture(KdTexture* c_tex) { m_ResultBackTex = c_tex; }

private:
	KdTexture*		m_TitleBackTex;		//�^�C�g����ʂ̔w�i�e�N�X�`��
	KdTexture*		m_GameBackTex;		//�Q�[����ʂ̔w�i�e�N�X�`��
	KdTexture*		m_ResultBackTex;		//���U���g��ʂ̔w�i�e�N�X�`��
	Math::Vector2	m_Pos;				//���W
	Math::Vector2	m_Move;				//�ړ�
	Math::Vector2	m_Image;			//�摜�̑傫��
	Math::Vector2	m_Scale;			//�g���
	Math::Matrix	m_Mat;				//�s��
	Math::Matrix	m_Scalemat;			//�g�k�s��
	Math::Matrix	m_Tansmat;			//�ړ��s��
	float			m_MovePow;			//�ړ���
};