#ifndef __HRocker_H__
#define __HRocker_H__

#include "cocos2d.h"
USING_NS_CC;


#define PI 3.1415926



typedef enum {
    tag_rocker,
    tag_rockerBG,
}tagForHRocker;
enum hero_direction
{
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    UP = 4,
    RIGHT_DOWN = 5,
    LEFT_DOWN = 6,
    RIGHT_UP = 7,
    LEFT_UP = 8
};

class HRocker : public cocos2d::Layer{
public:
    //ҡ��ƫ����
    float dx, dy;
    //����
    int direction;
    //�Ƿ�ɲ���ҡ��
    bool isCanMove;
    //����ҡ��
    static HRocker* createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position);
    //����ҡ��
    void startRocker(bool _isStopOther);
    //ֹͣҡ��
    void stopRocker();
private:

    EventListenerTouchOneByOne* listener;
    void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);
    //�õ��뾶Ϊr��Բ���˶���һ���Ƕȵ�xy����
    Point getAnglePosition(float r, float angle);
    
    //�õ�ҡ�����û�������ĽǶ�
    float getRad(Point pos1, Point pos2);
    //ҡ�˱���������
    Point rockerBGPosition;
    //ҡ�˱����İ뾶
    float rockerBGR;
    //�����¼�
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchMoved(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    CREATE_FUNC(HRocker);
};

#endif