#ifndef _PATH_FINDING_
#define _PATH_FINDING_


#include "cocos2d.h"
#include<vector>
#include<math.h>
#include<gedian.h>
using namespace std;
USING_NS_CC;
bool isInChosedPositions(vector<Vec2>& chosedPs, Vec2& possibleP);
int FindShortest(vector<int>& possibleCosts);
int getLength(Vec2& point1, Vec2& point2);
bool isAbandoned(Vec2& P, vector<Vec2>& abandonedPs);
Vec2 isThrough(int delta_x, int delta_y, int order);
bool isWalkable(Vec2& P1, Vec2& P2, const GridMap* gamemap);


//�������ŵ�·��
vector<Vec2> searchPathForTile(const GridMap* gamemap, Vec2& startPosition, Vec2& endPosition);


//����Ƭ����ת��ΪOpenGL����
//vector<Vec2> transferToOpenGLCoord(vector<Vec2>& chosedPs, MyMap* tileMap);


//��OpenGL����ת��Ϊ��Ƭ����
//Vec2 tileCoordFromPosition(Vec2 pos, TMXTiledMap* _tileMap);

/*Vec2 tileCoordFromPosition(Vec2 pos, TMXTiledMap* _tileMap)
{
	Vec2 size = _tileMap->getMapSize();
	Vec2 Size = _tileMap->getTileSize();
	Vec2 TileMapPos = _tileMap->getPosition();
	int x = (2 * Size.y * (pos.x - TileMapPos.x) - Size.x * (2 * pos.y - size.x * Size.y - 2 * TileMapPos.y)) / (2 * Size.x * Size.y) - 1;
	int y = (Size.x * (size.y * Size.y - 2 * pos.y + 2 * TileMapPos.y) + Size.x * Size.y * (size.x + size.y) + 2 * Size.y * (TileMapPos.x - pos.x)) / (2 * Size.x * Size.y) - 1;
	return Vec2((float)x, (float)y);
}
vector<Vec2> transferToOpenGLCoord(vector<Vec2>& chosedPs,TMXLayer* tilelayer, TMXTiledMap* tilemap)
{
	for (int i = 0; i < chosedPs.size(); i++)
	{
		chosedPs[i] = tilelayer->getPositionAt(chosedPs[i]) + Vec2(tilemap->getTileSize().width / 2, tilemap->getTileSize().height / 2);
	}
	return chosedPs;
}*/

#endif //_PATH_FINDING_