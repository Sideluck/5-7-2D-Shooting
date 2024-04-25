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

	KdTexture*		m_IdleTex;		//立ち姿のテクスチャ
	KdTexture*		m_RunTex;		//走る姿のテクスチャ
	KdTexture*		m_JumpTex;		//ジャンプした時のテクスチャ
	Math::Vector2	m_Pos;			//座標
	Math::Vector2	m_Move;			//移動
	Math::Vector2	m_Image;		//画像の大きさ
	Math::Matrix	m_Mat;			//行列
	Math::Matrix	m_Scalemat;		//拡縮行列
	Math::Matrix	m_Tansmat;		//移動行列
	float			m_ScaleX;		//横の拡大量
	float			m_ScaleY;		//縦の拡大量
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
};