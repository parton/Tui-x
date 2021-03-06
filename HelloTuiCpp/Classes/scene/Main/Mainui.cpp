﻿#include "Mainui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/tuiTag_main.h"
#include "dialog/MsgBox.h"

NS_MAIN_BEGIN

void Mainui::onLoadScene()
{
	setAutoRemoveUnusedTexture(true);
	TuiManager::getInstance()->parseScene(this,"panel_main",PATH_MAIN);

	//注册事件
	CControlView *ctlv = (CControlView*)this->getControl(PANEL_MAIN,CTLV_LEFT);
	ctlv->setOnControlListener(this,ccw_control_selector(Mainui::event_ctlv_left));

	CButton *pBtnOk = (CButton*)this->getControl(PANEL_MAIN,BTN_OK);
	pBtnOk->setOnClickListener(this,ccw_click_selector(Mainui::event_btn_ok));

	CButton *pBtnGo = (CButton*)this->getControl(PANEL_MAIN,BTN_GO);
	pBtnGo->setOnClickListener(this,ccw_click_selector(Mainui::event_btn_go));

	CButton *pBtnPhone = (CButton*)this->getControl(PANEL_MAIN, BTN_SHOWPHONE);
	pBtnPhone->setOnClickListener(this, ccw_click_selector(Mainui::event_btn_showphone));

	CButton *pBtnBag = (CButton*)this->getControl(PANEL_MAIN, BTN_BAG);
	pBtnBag->setOnClickListener(this, ccw_click_selector(Mainui::event_btn_bag));

	CButton *pBtnRecombine = (CButton*)this->getControl(PANEL_MAIN, BTN_RECOMBINE);
	pBtnRecombine->setOnClickListener(this, ccw_click_selector(Mainui::event_btn_recombine));

	CToggleView *pTgvA = (CToggleView*)this->getControl(PANEL_MAIN, TGV_A);
	pTgvA->setOnCheckListener(this, ccw_check_selector(Mainui::event_tgvA_check));

	CToggleView *pTgvB = (CToggleView*)this->getControl(PANEL_MAIN, TGV_B);
	pTgvB->setOnCheckListener(this, ccw_check_selector(Mainui::event_tgvB_check));

	MovieView *pMovie = (MovieView*)this->getControl(PANEL_MAIN, MOVIE_TEST);
	map<string, function<void()>> m;
	m["finish"] = bind(&Mainui::event_movie_finish, this);
	pMovie->setCallBack(m);

	//播放骨骼动画(默认不播放)
	Armature *armature = (Armature*)this->getControl(PANEL_MAIN,ARMATURE_BOSS1);
	armature->getAnimation()->play("live",-1,1);
}

void Mainui::event_ctlv_left( Ref* pSender, float fx, float fy )
{
	Sprite *pIcon = (Sprite*)this->getControl(PANEL_MAIN,ANIM_COIN);
	pIcon->setPosition(pIcon->getPosition() + Point(fx,fy));
}

void Mainui::event_movie_finish()
{
	CCLOG("movie finish!!");
}

void Mainui::event_tgvA_check(Ref *pSender, bool bChecked)
{
	MovieView *pMovie = (MovieView*)this->getControl(PANEL_MAIN, MOVIE_TEST);
	if (bChecked){
		pMovie->play(true);
	}else{
		pMovie->stop();
	}
}

void Mainui::event_tgvB_check(Ref *pSender, bool bChecked)
{
	MovieView *pMovie = (MovieView*)this->getControl(PANEL_MAIN, MOVIE_TEST);
	pMovie->setVisible(!bChecked);
	pMovie->isVisible() ? pMovie->play(true) : pMovie->stop();
}

void Mainui::event_btn_ok(Ref* pSender)
{
	//开启塑形
	//this->setModalable(true);
	CSceneManager::getInstance()->runUIScene(LoadScene("Main::MsgBox"));
}

void Mainui::event_btn_showphone(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("ShowPhone::ShowPhoneui")));
}

void Mainui::event_btn_go(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Store::Storeui")));
	
}

void Mainui::event_btn_bag(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Bag::Bagui")));
}

void Mainui::event_btn_recombine(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Recomebineui")));
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
Node* Mainui::getPanel( int tagPanel )
{
	Node *pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_MAIN:
		pPanel = this->getChildByTag(PANEL_MAIN);
		break;
	}
	return pPanel;
}


NS_MAIN_END 