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
    //摇杆偏移量
    float dx, dy;
    //方向
    int direction;
    //是否可操作摇杆
    bool isCanMove;
    //创建摇杆
    static HRocker* createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position);
    //启动摇杆
    void startRocker(bool _isStopOther);
    //停止摇杆
    void stopRocker();
private:

    EventListenerTouchOneByOne* listener;
    void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);
    //得到半径为r的圆周运动上一个角度的xy坐标
    Point getAnglePosition(float r, float angle);
    
    //得到摇杆与用户触屏点的角度
    float getRad(Point pos1, Point pos2);
    //摇杆背景的坐标
    Point rockerBGPosition;
    //摇杆背景的半径
    float rockerBGR;
    //触屏事件
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchMoved(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    CREATE_FUNC(HRocker);
};

#endif