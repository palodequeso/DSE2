#include "engine/include/core/system.h"

namespace DSE {
    namespace Core {
        System::System(void) {
            //
        }

        System::~System(void) {
            //
        }

        void System::Run(void) {
            //
        }
        
        void System::Execute(void) {
            Run();
        }

        
        SelfManagedSystem::SelfManagedSystem(void) {
            //
        }
        
        SelfManagedSystem::~SelfManagedSystem(void) {
            //
        }
        
        void SelfManagedSystem::Run(void) {
            //
        }
        
        void SelfManagedSystem::Execute(void) {
            Run();
        }
    }
}