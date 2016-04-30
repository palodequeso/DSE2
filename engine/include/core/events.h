#ifndef DSE_EVENTS_H
#define DSE_EVENTS_H

#include <cstddef>
#include <vector>
#include <unordered_map>

#define DSEEvents DSE::Core::Events::Instance()

namespace DSE {
    namespace Core {
        class Event {
            public:
                Event(void);
                ~Event(void);
            private:
                std::string name;
        };
        
        class Events {
            public:
                Events(void);
                ~Events(void);
                
                static Events *Instance();
                
                void Push(std::string event_name, Event *event);
                std::vector<Event *> GetEventsByName(std::string name);
                void Clear(void);

            private:
                static Events *singleton_instance;
                
                std::unordered_map<std::string, std::vector<Event *> > events;
        };
    }
}

#endif
