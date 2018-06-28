#include"pathFinding.h"


bool isInChosedPositions(vector<GridPoint>& chosedPs, GridPoint& possibleP)
{
	for (int i = 0; i < chosedPs.size(); i++)
	{
		if (chosedPs[i].x == possibleP.x && chosedPs[i].y == possibleP.y)     //�ж�ĳ�����ܵ�λ���Ƿ�����ѡ�е�λ����
		{
			return true;
		}
	}
	return false;
}

int FindShortest(vector<int>& possibleCosts)
{
	int shortest = 0;
	int size = possibleCosts.size();
	if (size != 0)
	{
		int smaller = possibleCosts[0];
		for (int i = 0; i < size; i++)
		{
			if (possibleCosts[i] < smaller)          //�����п��ܵ�λ�õ��������ҳ���С��
			{
				smaller = possibleCosts[i];
				shortest = i;
			}
		}
		return shortest;
	}
	return -1;
}

int getLength(GridPoint& point1, GridPoint& point2)
{
	int delta_x = point1.x - point2.x;
	int delta_y = point1.y - point2.y;
	float length = (float)(delta_x * delta_x + delta_y * delta_y);   //�õ�����λ��֮����������
	length = sqrtf(length);
	int Length = length * 10;
	return Length;
}

bool isAbandoned(GridPoint& P, vector<GridPoint>& abandonedPs)
{
	for (auto i : abandonedPs)
	{
		if (i.x == P.x && i.y == P.y)        //�ж�ĳ�����Ƿ��Ѿ�������
			return true;
	}
	return false;
}

GridPoint isThrough(int delta_x, int delta_y, int order)
{
	if (delta_x == 0)
		return GridPoint(0, delta_y);
	else if (delta_y == 0)
		return GridPoint(delta_x, 0);
	else
	{                                                                  //�õ�ֱ��ʱ���ܾ�����Ƭ��������
		int start = ((order - 1) * delta_y) / delta_x;
		int end = (order * delta_y) / delta_x;
		return GridPoint(start, end);
	}
}

bool isWalkable(GridPoint& P1, GridPoint& P2, const GridMap *gamemap)
{
	
	int delta_x = -1;
	int delta_y = -1;
	int x_diff = P2.x - P1.x;
	int y_diff = P2.y - P1.y;
	if (x_diff > 0)
		delta_x = 1;
	if (y_diff > 0)
		delta_y = 1;
	for (int i = 0; i <= abs(x_diff); i++)
	{                                                                          //�ж�����λ���ܷ�ֱ��
		GridPoint s_n = isThrough(abs(x_diff) + 1, abs(y_diff) + 1, i + 1);
		for (int j = s_n.x; j <= s_n.y && j <= abs(y_diff); j++)
		{
			if (!gamemap->gmap[int(P1.x + i * delta_x)][int(P1.y + j * delta_y)] && !(i == 0 && j == 0))
			{
				return false;
			}
		}
	}
	return true;
}

//�������ŵ�·��
vector<GridPoint> searchPathForTile(const GridMap*gamemap, GridPoint& startPosition, GridPoint& endPosition)
{
	int index = -1;
	vector<GridPoint> possiblePositions;
	vector<int> possibleCostsA;
	vector<int> possibleCosts;
	vector<int> chosedCosts;
	vector<int> chosedCostsA;
	vector<GridPoint>abandonedPositions;
	vector<GridPoint> chosedPositions;
	vector<GridPoint> finalPositions;
	GridPoint possiblePosition;
	chosedPositions.push_back(startPosition);
	chosedCostsA.push_back(0);
	finalPositions.push_back(startPosition);
	do
	{
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (i != 0 || j != 0)
				{
					possiblePosition.x = startPosition.x + i;
					possiblePosition.y = startPosition.y + j;
					if (possiblePosition.x >= 0 && possiblePosition.y >= 0 && possiblePosition.x < 200 && possiblePosition.y < 200 && gamemap->gmap[int(possiblePosition.x)][int(possiblePosition.y)] && !isAbandoned(possiblePosition, abandonedPositions) && isWalkable(chosedPositions[chosedPositions.size() - 1], possiblePosition,gamemap))
					{
						int manhattonDistance = 10 * (abs(endPosition.x - possiblePosition.x) + abs(endPosition.y - possiblePosition.y));
						//int manhattonDistance = getLength(possiblePosition, endPosition);
						if (!isInChosedPositions(chosedPositions, possiblePosition))
						{
							possiblePositions.push_back(possiblePosition);
							if (i * j == 0)
							{
								possibleCostsA.push_back(10);
								possibleCosts.push_back(manhattonDistance + 10);
							}
							else
							{
								possibleCosts.push_back(manhattonDistance + 14);
								possibleCostsA.push_back(14);
							}
						}
					}
				}
			}
		}
		index = FindShortest(possibleCosts);
		if (index >= 0)
		{
			if (chosedPositions.size() >= 2 && getLength(chosedPositions[chosedPositions.size() - 2], possiblePositions[index]) < chosedCostsA[chosedCostsA.size() - 1] + possibleCostsA[index] && isWalkable(chosedPositions[chosedPositions.size() - 2], possiblePositions[index],gamemap))
			{
				abandonedPositions.push_back(chosedPositions[chosedPositions.size() - 1]);
				chosedPositions.pop_back();
				chosedCostsA.pop_back();
				chosedCosts.pop_back();
			}
			chosedCostsA.push_back(possibleCostsA[index]);
			chosedPositions.push_back(possiblePositions[index]);
			chosedCosts.push_back(possibleCosts[index]);
			startPosition.x = possiblePositions[index].x;
			startPosition.y = possiblePositions[index].y;
		}
		else
			if (abandonedPositions.size() != 0)
				abandonedPositions.pop_back();
		if (possiblePositions.size() != 0)
			possiblePositions.clear();
		if (!possibleCostsA.empty())
			possibleCostsA.clear();
		if (possibleCosts.size() != 0)
			possibleCosts.clear();
	} while (chosedPositions[chosedPositions.size() - 1].x != endPosition.x || chosedPositions[chosedPositions.size() - 1].y != endPosition.y);
	GridPoint temp = chosedPositions[0];
	for (int i = 1; i < chosedPositions.size(); i++)
	{
		if (!isWalkable(temp, chosedPositions[i],gamemap))
		{
			finalPositions.push_back(chosedPositions[i - 1]);
			temp = chosedPositions[i - 1];
		}
	}
	finalPositions.push_back(chosedPositions[chosedPositions.size() - 1]);
	return finalPositions;
}


//����Ƭ����ת��ΪOpenGL����
/*vector<Vec2> transferToOpenGLCoord(vector<Vec2>& chosedPs, MyMap* tileMap)
{
	//float width = tileMap->getTileSize().width;
	//float height = tileMap->getTileSize().height;
	float width = 64.0f;
	float height = 32.0f;
	int TileHeight = tileMap->getMapSize().height;
	Vec2 MapPosition = tileMap->getPosition();
	for (int i = 0; i < chosedPs.size(); i++)
	{
		chosedPs[i].x = (chosedPs[i].x + 0.5) * width + MapPosition.x;
		chosedPs[i].y = (TileHeight - (chosedPs[i].y + 0.5)) * height + MapPosition.y;
	}
	return chosedPs;
}*/
//��OpenGL����ת��Ϊ��Ƭ����
/*Vec2 tileCoordFromPosition(Vec2 pos, TMXTiledMap* _tileMap)
{
	int x = (pos.x - _tileMap->getPosition().x) / _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - pos.y + _tileMap->getPosition().y) / _tileMap->getTileSize().height;
	return Vec2(x, y);
}*/