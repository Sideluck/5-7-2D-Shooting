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
	KdTexture*		m_BackTex;		//背景テクスチャ
	Math::Vector2	m_Pos;			//座標
	Math::Vector2	m_Move;			//移動
	Math::Vector2	m_Image;		//画像の大きさ
	Math::Vector2	m_Scale;		//拡大量
	Math::Matrix	m_Mat;			//行列
	Math::Matrix	m_Scalemat;		//拡縮行列
	Math::Matrix	m_Tansmat;		//移動行列
	float			m_MovePow;		//移動量
};