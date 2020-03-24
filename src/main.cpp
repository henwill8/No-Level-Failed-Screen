#include "../include/main.hpp"

bool enabled = false;
// Hook a void instance method: FireworksController.OnEnable()
MAKE_HOOK_OFFSETLESS(ShowEffect, void, Il2CppObject* self) {
    ShowEffect(self);

    Il2CppObject* animator;
    il2cpp_utils::GetFieldValue(&animator, self, "_animator");

    il2cpp_utils::RunMethod(animator, "set_enabled", enabled);
}

extern "C" void load() {
    log(INFO, "Hello from il2cpp_init!");
    log(INFO, "Installing hooks...");
    INSTALL_HOOK_OFFSETLESS(ShowEffect, il2cpp_utils::FindMethodUnsafe("", "LevelFailedTextEffect", "ShowEffect", 0));
    log(INFO, "Installed all hooks!");
}