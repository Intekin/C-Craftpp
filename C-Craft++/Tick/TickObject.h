#pragma once

class TickObject
{
public:
	virtual ~TickObject() = default;
	virtual void TickUpdate(unsigned int tickTime) = 0;
};