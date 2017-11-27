#include "Random.h"

RandomSingelton& RandomSingleton::get()
{
	static RandomSingelton r;
	return r;
}

RandomSingelton::RandomSingelton()
{
	m_randomEngine.seed(std::time(nullptr));
	for (int i = 0; i < 5; i++)
		intInRange(i, i * 5);
}