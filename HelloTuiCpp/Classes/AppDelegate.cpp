﻿#include "AppDelegate.h"
#include "module/ResoureMgr.h"
#include "tui/TuiManager.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

	Size size = Size(800,480);
	glview->setDesignResolutionSize(size.width,size.height,ResolutionPolicy::NO_BORDER);
	glview->setFrameSize(size.width,size.height);

    // turn on display FPS
    director->setDisplayStats(true);

    director->setAnimationInterval(1.0 / 60);

	//regist scene
	ResoureMgr::getInstance()->registScene();
    // run
	CSceneManager::getInstance()->runWithScene(LoadScene("Welcome::Welcomeui"));

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
 