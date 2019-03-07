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
        static void addListerner(SnakeEvent e, Callbackfn fn);
        static void fire(SnakeEvent e);
    private:
        EventSystem();
        virtual ~EventSystem();
        static std::map<SnakeEvent, std::vector<Callbackfn>> m_listeners;
};

#endif // EVENTSYSTEM_H
