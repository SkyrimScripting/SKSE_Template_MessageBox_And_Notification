#include "EventHandler.h"

void OnPlayerActivateItem(std::string itemName) {
    // This is the message that we want to show
    auto message = std::format("Player activated {}", itemName);

    // Popup a "Debug MessageBox" (with an OK button)
    RE::DebugMessageBox(message.c_str());

    // Show a "Debug Notification" (displays in the top-left corner of the game)
    RE::DebugNotification(message.c_str());
}

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);
    // We need to do *something* in the game to activate our "MessageBox" and "Notification".
    // This registers an "EventHandler" to handle whenever any object in the game is "Activated".
    // If the *player* activated the object, the name of the activated object is passed to OnPlayerActivateItem() above.
    // If you are curious about the event handler, see EventHandler.h
    // But you can also see more examples of game event handlers in the template:
    //                                                       https://github.com/SkyrimScripting/SKSE_Template_GameEvents
    RE::ScriptEventSourceHolder::GetSingleton()->AddEventSink<RE::TESActivateEvent>(new EventHandler());
    return true;
}
