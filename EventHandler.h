#pragma once

// ... shhh ... don't worry about this part of the code ... you can learn about it in:
//                                                          https://github.com/SkyrimScripting/SKSE_Template_GameEvents

void OnPlayerActivateItem(std::string);

class EventHandler : public RE::BSTEventSink<RE::TESActivateEvent> {
public:
    RE::BSEventNotifyControl ProcessEvent(const RE::TESActivateEvent* event,
                                          RE::BSTEventSource<RE::TESActivateEvent>*) override {
        if (event->actionRef->GetFormID() == 0x14) {
            std::string activated = event->objectActivated->GetBaseObject()->GetName();
            if (activated.empty()) activated = "<unnamed>";
            OnPlayerActivateItem(activated);
        }
        return RE::BSEventNotifyControl::kContinue;
    }
};
