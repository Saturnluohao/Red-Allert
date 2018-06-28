#include "BaseOfAll.h"


 Basement::Basement()
 {
	SetVisible(false);
	BloodProgress->setType(kCCProgressTimerTypeBar);
	BloodProgress->setMidpoint(ccp(0, 0));
	BloodProgress->setBarChangeRate(ccp(1, 0));            //���캯��������Ѫ�����ɼ�
	BloodProgress->setPercentage(100.0f);
}
void Basement::SetVisible(bool judge)
{
	BloodBackground->setVisible(judge);                  //����Ѫ���Ƿ�ɼ�
	BloodProgress->setVisible(judge);
}
bool Basement::minusBloodAmount(float attack)
{
	if (BloodProgress->getPercentage() - attack <= 0)
	{
		BloodProgress->setPercentage(0);              //�ܵ�����Ѫ������
		return false;
	}
	else
	{
		BloodProgress->setPercentage(BloodProgress->getPercentage() - attack);
		return true;
	}
}

void Basement::setpos(Vec2 position)
{
	this->pos = position;
}
void Basement::setgamemap(MyMap* Gamemap)
{
	this->gamemap = Gamemap;
}
void Basement::setgridmap(GridMap* Gridmap)
{
	this->gridmap = Gridmap;
}
void Basement::setgmap()
{
	for (int i = pos.x; i < pos.x + 2; i++)
	{
		for (int j = pos.y; j < pos.y + 2; j++)
		{
			gridmap->gmap[i][j] = 0;
		}
	}
}
void Basement::resetgmap()
{
	for (int i = pos.x; i < pos.x + 2; i++)
	{
		for (int j = pos.y; j < pos.y + 2; j++)
		{
			gridmap->gmap[i][j] = 1;
		}
	}
}


