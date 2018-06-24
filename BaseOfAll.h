#pragma once
#include "cocos2d.h"
#include<string>
using namespace std;
USING_NS_CC;

typedef enum
{
	TypeBase = 0,
	TypeSodier,
	TypePowerPlant,
	TypeMineField,
	TypeBarrack,
	TypeWarmachineFactory,
	TypePatrolDog,
	TypeTank,
	TypeBullet
}Types;
class Basement : public Sprite
{
	CC_SYNTHESIZE(float, attackRate, AttackRate);          //�ܹ������ۺ���
	CC_SYNTHESIZE(float, buildTime, BuildTime);            //�����ʱ
public:
	Basement();
	bool minusBloodAmount(float attack);              //�ܵ����������Ѫ��
	void SetVisible(bool judge);         //����Ѫ���Ƿ�ɼ�
	virtual void handleBulletCollidingWithEnemy(Layer* layer, float attack) = 0;
protected:
	Sprite* BloodBackground = Sprite::createWithSpriteFrameName("bloodBackground.png");   //Ѫ������
	Sprite* Blood = Sprite::createWithSpriteFrameName("blood.png");               //Ѫ��         
	ProgressTimer* BloodProgress = ProgressTimer::create(Blood);             //Ѫ��������
};
