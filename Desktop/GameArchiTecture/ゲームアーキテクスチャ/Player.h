#pragma once
class Enemy;
//�w�b�_�[�Ńw�b�_�[���Ă΂Ȃ�
class Player
{
	Enemy* enemy_;
	int life_ = 100;
public:
	void OnDamage(int damage);
	void Attack();
};