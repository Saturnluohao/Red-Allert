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
