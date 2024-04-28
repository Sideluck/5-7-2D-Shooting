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

	KdTexture*		m_RightBulletTex;	//弾のテクスチャ(右)
	KdTexture*		m_LeftBulletTex;	//弾のテクスチャ(左)
	Math::Vector2	m_Pos;				//座標
	Math::Vector2	m_Move;				//移動
	Math::Vector2	m_Image;			//画像の大きさ
	Math::Vector2	m_Scale;			//拡大量
	Math::Matrix	m_Mat;				//行列
	Math::Matrix	m_Scalemat;			//拡縮行列
	Math::Matrix	m_Tansmat;			//移動行列
	float			m_MovePow;			//移動量
	bool			m_AliveFlg;			//生存フラグ
	bool			m_FireFlg;			//弾発射フラグ
};