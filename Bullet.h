#pragma once
#include "cocos2d.h"
#include "BaseOfAll.h"
USING_NS_CC;
class Bullet : public Sprite
{
	CC_SYNTHESIZE(Vec2, velocity, Velocity);    //�ӵ��ٶ�
	CC_SYNTHESIZE(float, attack, Attack);       //�ӵ�������
public:
	void shootBulletFromBasement(Basement* basement, float direction);         //�����ӵ����������
	virtual void update(float dt);             //ʹ�ӵ��ƶ�
	static Bullet* createWithSpriteFrameName(const char* spriteFrameName);       //�ӵ���̬���캯��
};