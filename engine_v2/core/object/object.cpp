#include "object.h"

object::object()
	:mPosition({ 0,0,0,0 })
{

}

void object::setPosition(const SDL_Rect& rect)
{
	mPosition = rect;
}

SDL_Rect object::getPosition()
{
	return mPosition;
}

SDL_Rect* object::getPtrPosition()
{
	return &mPosition;
}
