#include "Effect.h"

Effect::Effect()
{
}

Effect::~Effect()
{

}

Effect::Effect(string buffName, int duration)
{
	this->buffName = buffName;
	this->duration = duration;
}
