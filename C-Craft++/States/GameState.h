#ifndef STATEBASE_H_INCLUDED
#define STATEBASE_H_INCLUDED

#include <SFML/Graphics.hpp>

class RenderMaster;
class Application;

class GameState
{
    public:
		GameState(Application& app)
        :   m_pApplication  (&app)
        { }

        virtual ~GameState()  = default;

        virtual void handleEvent(sf::Event e) = 0;
        virtual void handleInput() = 0;

        virtual void update(float deltaTime) = 0;

        virtual void render(RenderMaster& renderer) = 0;

        virtual void onOpen() = 0;

    protected:
        Application* m_pApplication;



};

#endif // STATEBASE_H_INCLUDED
