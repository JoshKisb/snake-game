#include "eventsystem.h"
#include <assert.h>

// It is not necessary to have such an event system for this small project
// but I wanted to showcase a possible implementation for an Event system
EventSystem* EventSystem::sInstance = nullptr;

EventSystem::EventSystem()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

EventSystem::~EventSystem()
{
    //dtor
}

void EventSystem::addListerner(SnakeEvent e, Callbackfn fn)
{
    sInstance->m_listeners[e].push_back(fn);
}

void EventSystem::fire(SnakeEvent e)
{
    std::vector<Callbackfn> callbacks = sInstance->m_listeners[e];
    for (auto callback: callbacks) {
        callback();
    }
}

