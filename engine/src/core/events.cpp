#include "engine/include/core/events.h"

namespace DSE {
    namespace Core {
        Event::Event(void) {
            //
        }
        
        Event::~Event(void) {
            //
        }
        
        Events *Events::singleton_instance = NULL;
        
        Events *Events::Instance() {
            if (!singleton_instance) {
                singleton_instance = new Events();
            }
            return singleton_instance;
        }

        Events::Events(void) {
            //
        }

        Events::~Events(void) {
            Clear();
        }
        
        void Events::Clear(void) {
            auto iter = events.begin();
            while (iter != events.end()) {
                auto event_iter = iter->second.begin();
                while (event_iter != iter->second.end()) {
                    event_iter++;
                }
                iter++;
            }
            events.clear();
        }
        
        void Events::Push(std::string event_name, Event *event) {
            events[event_name].push_back(event);
        }
        
        std::vector<Event *> GetEventsByName(std::string name);
    }
}
