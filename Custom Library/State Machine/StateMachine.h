#pragma once
#include "EStates.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update();
	void ChangeState(EGameStates eNewState);

private:
	EGameStates m_eGameState = ESTATE_MAINMENU;
};

