#ifndef DSE_APPLICATION_H
#define DSE_APPLICATION_H

namespace DSE {
    namespace Core {
        class Application {
            public:
                Application(void);
                ~Application(void);

                void Start(void);
            private:
                bool running;
        };
    }
}

#endif
