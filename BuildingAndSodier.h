#ifndef _BUILDING_AND_SODIER_
#define _BUILDING_AND_SODIER_
#include "BaseOfAll.h"
#include "Bullet.h"
#include "MoveControl.h"


class Base : public Basement
{
public:
	static Base* create();                  //��̬���캯��
	virtual void handleBulletCollidingWithEnemy(float attack);      //���������¼�
	static float BaseBT;

};


class Sodier : public Basement
{
public:
	static Sodier* create();
	void updateSodier(float dt);       //ʵʱ������޵��˲����𹥻�
	static float SodierBT;
	virtual void handleBulletCollidingWithEnemy(float attack);
private:
	float direction; //��¼���˵ķ�λ
};


class PowerPlant : public Basement
{
public:
	static PowerPlant* create();
	virtual void handleBulletCollidingWithEnemy(float attack);
	static float PowerPlantBT;

};


class MineField : public Basement
{
public:
	static MineField* create();
	virtual void handleBulletCollidingWithEnemy(float attack);
	static float MineFieldBT;
};


class Barrack : public Basement
{
public:
	static Barrack* create();
	virtual void handleBulletCollidingWithEnemy(float attack);
	static float BarrackBT;
};


class WarMachine_Factory : public Basement
{
public:
	static WarMachine_Factory* create();
	virtual void handleBulletCollidingWithEnemy( float attack);
	static float WarMachineFactoryBT;
};


class PatrolDog : public Basement
{
public:
	static PatrolDog* create();
	virtual void update(float dt);
	virtual void handleBulletCollidingWithEnemy( float attack);
	void setenemy(Sodier* _enemy) { enemy = _enemy; }
	static float PatrolDogBT;
private:
	float direction;
	Sodier* enemy;
};
class Tank : public Basement
{
public:
	static Tank* create();
	virtual void updateTank(float dt);
	virtual void handleBulletCollidingWithEnemy(float attack);
	static float TankBT;
private:
	float direction;
};
bool isEnemy(Basement* basement);


void setTime(bool judge);

float directionAngle(Vec2 delta);

Vec2 searchEnemy(Vector<Basement*> sprites, Basement* self, float& direction);

#endif //_BUILDING_AND_SODIER_