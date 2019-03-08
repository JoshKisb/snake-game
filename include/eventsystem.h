#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <functional>
#include <vector>
#include <map>

typedef std::function<void()> Callbackfn;

enum class SnakeEvent {
    UP, DOWN, LEFT, RIGHT, NONE
};

class EventSystem
{
    public:
        EventSystem();
        virtual ~EventSystem();
        static void addListerner(SnakeEvent e, Callbackfn fn);
        static void fire(SnakeEvent e);
    private:
        std::map<SnakeEvent, std::vector<Callbackfn>> m_listeners;
        static EventSystem* sInstance;
};

#endif // EVENTSYSTEM_H
