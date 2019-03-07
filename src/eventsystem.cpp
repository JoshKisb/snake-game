#include "eventsystem.h"

// It is not necessary to have such an event system for this small project
// but I wanted to showcase a possible implementation for an Event system
std::map<SnakeEvent, std::vector<Callbackfn>> EventSystem::m_listeners {};

void EventSystem::addListerner(SnakeEvent e, Callbackfn fn)
{
    m_listeners[e].push_back(fn);
}

void EventSystem::fire(SnakeEvent e)
{
    std::vector<Callbackfn> callbacks = m_listeners[e];
    for (auto callback: callbacks) {
        callback();
    }
}

