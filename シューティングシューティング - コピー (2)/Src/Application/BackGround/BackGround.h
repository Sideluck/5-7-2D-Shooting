#pragma once
class BG
{
public:
	BG(){}
	~BG(){}

	//タイトル画面の背景
	void InitTitleBack();
	void UpdateTitleBack();
	void DrawTitleBack();
	
	//ゲーム画面の背景
	void InitGameBack();
	void UpdateGameBack();
	void DrawGameBack();

	//リザルト画面の背景
	void InitResultBack();
	void UpdateResultBack();
	void DrawResultBack();

	void SetTitleBackTexture(KdTexture* a_tex) { m_TitleBackTex = a_tex; }
	void SetGameBackTexture(KdTexture* b_tex) { m_GameBackTex = b_tex; }
	void SetResultBackTexture(KdTexture* c_tex) { m_ResultBackTex = c_tex; }

private:
	KdTexture*		m_TitleBackTex;		//タイトル画面の背景テクスチャ
	KdTexture*		m_GameBackTex;		//ゲーム画面の背景テクスチャ
	KdTexture*		m_ResultBackTex;		//リザルト画面の背景テクスチャ
	Math::Vector2	m_Pos;				//座標
	Math::Vector2	m_Move;				//移動
	Math::Vector2	m_Image;			//画像の大きさ
	Math::Vector2	m_Scale;			//拡大量
	Math::Matrix	m_Mat;				//行列
	Math::Matrix	m_Scalemat;			//拡縮行列
	Math::Matrix	m_Tansmat;			//移動行列
	float			m_MovePow;			//移動量
};