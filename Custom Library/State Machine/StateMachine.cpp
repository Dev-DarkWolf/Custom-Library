#include "StateMachine.h"

StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::Update()
{
	switch (m_eGameState)
	{
	case ESTATE_INTROSCENE:
		break;
	case ESTATE_MAINMENU:
		break;
	case ESTATE_OPTIONS:
		break;
	case ESTATE_PLAYGAME:
		break;
	case ESTATE_PAUSEGAME:
		break;
	case ESTATE_RESUMEGAME:
		break;
	case ESTATE_QUITGAME:
		break;
	default:
		break;
	}
}

void StateMachine::ChangeState(EGameStates eNewState)
{
	m_eGameState = eNewState;
}
