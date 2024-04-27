#pragma once

class Bullet
{
public:
	Bullet(){}
	~Bullet(){}

	void Init();
	void Update();
	void Draw();
	void Shot(Math::Vector2 a_shotPos);//発射速度

	const bool GetAlive() { return m_AliveFlg; }
	const Math::Vector2 GetPos() { return m_Pos; }

	void SetBulletTexture(KdTexture* a_tex) { m_BulletTex = a_tex; }

private:

	KdTexture*		m_BulletTex;	//弾のテクスチャ
	Math::Vector2	m_Pos;			//座標
	Math::Vector2	m_Move;			//移動
	Math::Vector2	m_Image;		//画像の大きさ
	Math::Vector2	m_Scale;		//拡大量
	Math::Matrix	m_Mat;			//行列
	Math::Matrix	m_Scalemat;		//拡縮行列
	Math::Matrix	m_Tansmat;		//移動行列
	float			m_MovePow;		//移動量
	bool			m_AliveFlg;		//生存フラグ
	bool			m_FireFlg;		//弾発射フラグ
};