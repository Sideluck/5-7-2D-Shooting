#pragma once

class Player
{
public:
	Player() {};
	~Player() {};

	void Init();
	void Update();
	void Draw();
	void DrawIdle();

	void SetTexture(KdTexture* a_tex) { m_tex = a_tex; }

private:

	KdTexture* m_tex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Vector2 m_image;
	Math::Matrix m_mat;
	Math::Matrix m_scalemat;
	Math::Matrix m_transmat;
	bool m_bAlive;
	float MovePow;
	float m_AnimCnt;
	float m_AnimSpeed;
	bool m_bJump;
	bool m_Idle;

};