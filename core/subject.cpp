// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "core/subject.h"
#include "core/observer.h"

Subject::Subject()
{
}

void Subject::notifyObservers()
{
    for (Observer* o : observers)
        o->notify();
}

void Subject::registerObserver(Observer* observer)
{
    observers.push_back(observer);
}
