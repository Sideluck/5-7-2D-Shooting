#pragma once

class Player
{
public:
	Player() {};
	~Player() {};

	void Init();
	void Update();
	void Draw();

	void SetTexture(KdTexture* a_tex) { m_tex = a_tex; }

private:

	KdTexture* m_tex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Matrix m_mat;
	Math::Matrix m_scalemat;
	Math::Matrix m_transmat;
	float m_scaleX;
	bool m_bAlive;
	bool m_bJump;

};