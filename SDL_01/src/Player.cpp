#include "LoaderParams.h"
#include "Player.h"
#include "SDLGameObject.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::clean()
{
	
}

void Player::handleInput()
{
	// Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	// m_velocity = (*vec - m_position)/10;

	if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	
	if(TheInputHandler::Instance()->joysticksInitialised())
	{
		if(TheInputHandler::Instance()->getAxisX(0, 1) > 0 || TheInputHandler::Instance()->getAxisX(0, 1) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->getAxisX(0, 1));
		}
		if(TheInputHandler::Instance()->getAxisY(0, 1) > 0 || TheInputHandler::Instance()->getAxisY(0, 1) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->getAxisY(0, 1));
		}
		if(TheInputHandler::Instance()->getAxisX(0, 2) > 0 || TheInputHandler::Instance()->getAxisX(0, 2) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->getAxisX(0, 2));
		}
		if(TheInputHandler::Instance()->getAxisY(0, 2) > 0 || TheInputHandler::Instance()->getAxisY(0, 2) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->getAxisY(0, 2));
		}
		if(TheInputHandler::Instance()->getButtonState(0, 3))
		{
			m_velocity.setX(1);
		}
	}
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
	}
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
	}
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		m_velocity.setY(-2);
	}
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		m_velocity.setY(2);
	}

}