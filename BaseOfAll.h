#ifndef _BASE_OF_ALL_
#define _BASE_OF_ALL_
#include "cocos2d.h"
#include<string>
#include"gedian.h"
#include"Map.h"
#include "GameMessage.pb.h"
#include "SocketClient.h"
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

	int id;
	int camp = 0;
	

	Basement();
	bool minusBloodAmount(float attack);              //�ܵ����������Ѫ��
	void SetVisible(bool judge);         //����Ѫ���Ƿ�ɼ�
	virtual void handleBulletCollidingWithEnemy(float attack) = 0;
	MyMap* gamemap;
	GridMap* gridmap;
	Vec2 pos;

	void setpos(Vec2 position);
	void setgamemap(MyMap* Gamemap);
	void setgridmap(GridMap* Gridmap);
	void setgmap();
	void resetgmap();
	GridPath grid_path;
protected:
	Sprite* BloodBackground = Sprite::createWithSpriteFrameName("bloodBackground.png");   //Ѫ������
	Sprite* Blood = Sprite::createWithSpriteFrameName("blood.png");               //Ѫ��         
	ProgressTimer* BloodProgress = ProgressTimer::create(Blood);             //Ѫ��������
};


























#endif //_BASE_OF_ALL_