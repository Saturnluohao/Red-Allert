#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
#include"Map.h"
#include"gedian.h"
#include "MoveControl.h"
#include"gamemanager.h"
#include"MyMenu.h"
#include "SocketServer.h"
#include "SocketClient.h"
USING_NS_CC;

class Manager;



class Money : public cocos2d::LabelBMFont
{
public:
	void update(float f) override;
	CREATE_FUNC(Money);
	bool init() override;
	/**
	* \brief update money on screen
	*/
	void updateMoneyDisplay();
	/**
	* \param cost cost
	* \return if money can cover the cost
	*/
	bool checkMoney(int cost) const;
	/**
	* \brief decrease cost in money
	* \param cost
	*/
	void spendMoney(int type);
	void resetMoney(int type);
	/**
	* \brief increase amount in money
	* \param amount
	*/
	void increaseMoney(int amount);
private:
	int money = 0;
	int timer = 0;
	//��Ǯ��������
	int inc_prd = 20;
	//��Ǯÿ������������
	int inc_amt = 20;
	
};


class HelloWorld : public cocos2d::Scene
{


public:
	GridMap * gridmap;
	MyMap * gamemap;
	Manager * manager;
	Menu * mymenu;
	Menu * createmenu();
	static HelloWorld* createScene(SocketServer* socket_server, SocketClient* socket_client);
	cocos2d::Vec2 MouseLocation;
	virtual bool init(SocketServer* server, SocketClient* client);
	// a selector callback
	void createBarrack(cocos2d::Ref* pSender);
	void createpowerplant(cocos2d::Ref* pSender);
	void createfield(cocos2d::Ref* pSender);
	void createfactory(cocos2d::Ref* pSender);
	void createsodier(cocos2d::Ref* pSender);
	void createpetroldog(cocos2d::Ref* pSender);
	void createTank(cocos2d::Ref* pSender);
	void screen_move(Vec2 position);
	void update(float dt);
	void focusonbase();
	bool hasbuildbarrack=false;
	bool hasbuildfactory=false;
	EventListenerMouse*building;
	EventListenerMouse*MouseSelect;
	EventListenerKeyboard* keycallback;
	void onKeyPressed(EventKeyboard::KeyCode keycode, cocos2d::Event* pEvent);

	bool checkmap = true;
	Size Mapsize;
	int buildingitem=0;
	Layer* layer1;
	Money * money = nullptr;
	EventListenerPhysicsContact *contactListener;
	virtual void onEnter();

	MenuItemImage* Bar;
	MenuItemImage* power;
	MenuItemImage* field;
	MenuItemImage* factory;
	MenuItemImage* soldier;
	MenuItemImage* dog;
	MenuItemImage* tank;

	int cur_ID;
	int player_ID;
	int num_player=4;
	Vec2 Base_pos;
	SocketServer* socket_server = nullptr;
	SocketClient* socket_client = nullptr;

	GameMessageSet msg_set;
};






#endif // __HELLOWORLD_SCENE_H__
