#pragma once
#include "ItemInBox.h"

class LuckyBox : public GameObject
{
	StateMachine<LuckyBox>*		m_stateMachine;

	ItemInBox*					m_item;
	int							m_countItem;

	ItemsType					m_type;

	bool						m_finishAnimation;

	int							m_currentFrame;
	std::vector<Frame>			m_frameList;

	int							m_timeAnimation;

	bool						m_makeEffect;
public:
	LuckyBox(ItemsType type, int countCoin = 1);
	~LuckyBox();

	void					setCurrentFrame(int frame){ m_currentFrame = frame; m_Sprite->setRect(m_frameList[m_currentFrame].rect); }
	int						getCurrentFrame(){ return m_currentFrame; }

	void					update();
	void					updateVelocity();
	void					draw(LPD3DXSPRITE SpriteHandler);

	int						getCountItem(){ return m_countItem; }
	void					setCountItem(int x){ m_countItem = x; }

	void					setTimeAnimation(int x){ m_timeAnimation = x; }
	int						getTimeAnimation(){ return m_timeAnimation; }

	StateMachine<LuckyBox>*	getStateMachine(){ return m_stateMachine; }

	int						getSizeFrameList(){ return m_frameList.size(); }
	void					setFrameList(vector<Frame> list){ m_frameList = list; }


	ItemInBox*				getItem(){ return m_item; }

	void					changeItemsType(ItemsType type);
	ItemsType				getType(){ return m_type; }

	void					setMakeEffect(bool x){ m_makeEffect = x; }
	bool					getMakeEffect(){ return m_makeEffect; }

};
