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

	KdTexture*		m_IdleTex;		//立ち姿のテクスチャ
	KdTexture*		m_RunTex;		//走る姿のテクスチャ
	KdTexture*		m_JumpTex;		//ジャンプした時のテクスチャ
	KdTexture*		m_IdleShotTex;	//立ち状態で銃を撃った時のテクスチャ
	KdTexture*		m_RunShotTex;	//走っている状態で銃を撃った時のテクスチャ
	Math::Vector2	m_Pos;			//座標
	Math::Vector2	m_Move;			//移動
	Math::Vector2	m_Image;		//画像の大きさ
	Math::Vector2	m_Scale;		//拡大量
	Math::Matrix	m_Mat;			//行列
	Math::Matrix	m_Scalemat;		//拡縮行列
	Math::Matrix	m_Tansmat;		//移動行列
	float			m_MovePow;		//移動量
	float			m_AnimCnt;		//アニメーションのページ
	float			m_AnimSpd;		//アニメーションの速度
	float			m_Gravity;		//重力
	float			m_JumpPow;		//ジャンプの高さ
	bool			m_AliveFlg;		//生存フラグ
	bool			m_JumpFlg;		//ジャンプしたかのフラグ
	bool			m_JumpAniFlg;	//ジャンプのアニメーションのフラグ
	bool			m_NotJumpFlg;	//連続ジャンプを防ぐためのフラグ
	bool			m_IdleFlg;		//今立ち姿(何もボタンを押していない)かのフラグ
	bool			m_Run_LeftFlg;	//今左に移動しているかのフラグ
	bool			m_Run_RightFlg;	//今右に移動しているかのフラグ
	bool			m_GunFlg;	//銃を撃った時のフラグ
};