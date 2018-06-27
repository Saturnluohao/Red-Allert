#include"gedian.h"
#include<vector>

USING_NS_CC;
//����GridPoint�����


bool GridPoint::operator==(const GridPoint& gp2) const
{
	return(x == gp2.x && y == gp2.y);
}

GridPoint GridPoint::operator+(const GridPoint& gp) const
{

	return GridPoint(this->x + gp.x, this->y + gp.y);
}
GridPoint GridPoint::operator-(const GridPoint & gp) const
{
	return GridPoint(this->x - gp.x, this->y - gp.y);
}

//����ͼ����
GridMap* GridMap::create(const MyMap*gamemap)
{
	GridMap *ret = new (std::nothrow) GridMap();
	if (ret->initWithTiledMap(gamemap))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);

	return nullptr;
}


bool GridMap::initWithTiledMap(const MyMap*gamemap)
{
	
	auto* upback = gamemap->up->getLayer("back");
	auto* leftback = gamemap->left->getLayer("back");
	auto* rightback = gamemap->right->getLayer("back");
	auto*downback = gamemap->down->getLayer("back");

	for (int i = 0; i<200; i++)
		for (int j = 0; j < 200; j++)
		{
			if (i / 100)
			{
				if (j / 100)
				{
					if (downback->getTileGIDAt(Vec2(i - 100, j - 100)) > 1)
						gmap[i][j] = 0;
					else
						gmap[i][j] = 1;
				}
				else
				{
					if (rightback->getTileGIDAt(Vec2(i - 100, j)) > 1)
						gmap[i][j] = 0;
					else
						gmap[i][j] = 1;
				}
			}
			else
			{
				if (j / 100)
				{
					if (leftback->getTileGIDAt(Vec2(i, j - 100)) > 1)
						gmap[i][j] = 0;
					else
						gmap[i][j] = 1;
				}
				else
				{
					if (upback->getTileGIDAt(Vec2(i, j)) > 1)
						gmap[i][j] = 0;
					else
						gmap[i][j] = 1;
				}
			}
		}

	map_height = gamemap->getMapSize().height;
	map_width = gamemap->getMapSize().width;

	return(true);
}

//������Ƿ�Ϊ��
bool GridMap::checkPosition(const Vec2& gp)
{
	if (gp.x >= 0 && gp.x < map_width && gp.y >= 0 && gp.y < map_height && gmap[int(gp.x)][int(gp.y)] == 1)
		return true;
	return false;
}

//�������ڸ���Ƿ�Ϊ��
bool GridMap::checkPositionRect(const Vec2 &gp)
{
	for (int i = gp.x; i < gp.x + 2; i++)
	{
		for (int j = gp.y; j < gp.y + 2; j++)
		{
			if (!checkPosition(Vec2(i, j)))
			{
				return false;
			}
		}
	}
	return true;
}


//ռ�ݸ��
bool GridMap::occupyPosition(int id, const Vec2& pos, bool occupy_grid)
{
	if (gmap[int(pos.x)][int(pos.y)] == 1)
	{
		gmap[int(pos.x)][int(pos.y)] = 0;
		return true;
	}
	else
		return false;
}

bool GridMap::occupyPositionInRect(int id, const Vec2& pos)
{
	for(int i=pos.x;i<pos.x+2;i++)
		for (int j = pos.y; j < pos.y + 2; j++)
		{
			if (!occupyPosition(id, Vec2(i, j)))
				return false;
		}
	return true;
}


//���õ��Ƿ��ڵ�ͼ��
bool GridMap::checkPointInMap(const GridPoint & gp) const
{
	return checkPointInMap(gp.x, gp.y);
}

bool GridMap::checkPointInMap(int x, int y) const
{
	return (x >= 0 && x < map_width && y >= 0 && y < map_height);
}

//��λ�����뿪��㣬���ø��
void GridMap::leavePosition(const GridPoint& pos, bool occupy_grid)
{
	if (occupy_grid)
		gmap[pos.x][pos.y] = 0;
	
}


//�����߼���


//����ID��


//���ؿ�ѡ��Χ�����еĵ�λID


//����ָ������ϵĵ�λID
