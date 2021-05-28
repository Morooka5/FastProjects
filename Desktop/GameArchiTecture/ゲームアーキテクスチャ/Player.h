#pragma once
class Enemy;
//ヘッダーでヘッダーを呼ばない
class Player
{
	Enemy* enemy_;
	int life_ = 100;
public:
	void OnDamage(int damage);
	void Attack();
};