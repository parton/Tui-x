#ifndef __ANIMATIONUTIL_H__
#define __ANIMATIONUTIL_H__

#include "cocos2d.h"
#include "../TuiMacros.h"

using namespace cocos2d;

class AnimationUtil{
public:
	static Animation* createAnimWithName(const char* name,float delay,unsigned int iLoops);
	static Animation* createAnimWithNameAndNum(const char* name,int iNum, float delay,unsigned int iLoops);
protected:
private:
};

#endif