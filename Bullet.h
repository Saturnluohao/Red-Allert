#ifndef _BULLET_
#define _BULLET_
#include "cocos2d.h"
#include "BaseOfAll.h"
#include "pathFinding.h"
#include<math.h>
#include"HelloWorldScene.h"
USING_NS_CC;


class Bullet : public Sprite
{
	CC_SYNTHESIZE(Vec2, velocity, Velocity);    //�ӵ��ٶ�
	CC_SYNTHESIZE(float, attack, Attack);       //�ӵ�������
public:
	void shootBulletFromBasement(Basement* basement, float direction, const char* effect);         //�����ӵ����������
	virtual void update(float dt);             //ʹ�ӵ��ƶ�
	static Bullet* createWithSpriteFrameName(const char* spriteFrameName);       //�ӵ���̬���캯��
};

#endif //_BULLET_