#include "../include/events.h"

Node* addNode(Node* head, const Event& e) {
    Node* newNode = new Node(e);
    if (!head) return newNode;

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

Node* buildEventsList(const ordered_json& eventData) {
    if (eventData.empty()) {
        std::cout << "No events found.\n";
        return nullptr;
    }

    Node* head = nullptr;

    for (const auto& item : eventData.items()) {
        const auto& eventData = item.value();
        Event e;

        // Required fields (assume always string)
        e.eventName = eventData.value("eventName", "");
        e.date = eventData.value("date", "");
        e.description = eventData.value("description", "");
        e.location = eventData.value("location", "");

        // Optional / nullable fields
        e.endDate = eventData.contains("endDate") && !eventData["endDate"].is_null() ? eventData["endDate"] : "";
        e.leader = eventData.contains("leader") && !eventData["leader"].is_null() ? eventData["leader"] : "";
        e.casualties = eventData.contains("casualties") && !eventData["casualties"].is_null() ? eventData["casualties"] : "";
        e.createdBy = eventData.contains("createdBy") && !eventData["createdBy"].is_null() ? eventData["createdBy"] : "";

        // Participants array -> comma-separated string
        if (eventData.contains("participants") && eventData["participants"].is_array()) {
            for (const auto& p : eventData["participants"]) {
                if (!p.is_null()) {
                    e.participants += p.get<std::string>() + ", ";
                }
            }
            // Remove last ", " if added
            if (!e.participants.empty()) {
                e.participants.erase(e.participants.size() - 2);
            }
        }

        head = addNode(head, e);
    }

    return head;
}

void printEvents(Node* head) {
    if (!head) {
        std::cout << "No events to display.\n";
        return;
    }

    Node* current = head;

    while (current) {
        Event& e = current->data;

        std::cout << "\n\n+";
        for (int i = 0; i < 85; i++) std::cout << "-";
        std::cout << "+\n\n";

        std::cout << "Event: " << e.eventName;
        std::cout << "\nDate: " << e.date;
        if (!e.endDate.empty()) std::cout << "\nEnd Date: " << e.endDate;
        std::cout << "\nDescription: " << wrapText(e.description);
        if (!e.leader.empty()) std::cout << "\nLeader: " << e.leader;
        if (!e.casualties.empty()) std::cout << "\nCasualties: " << e.casualties;
        std::cout << "\nParticipants: " << e.participants;
        std::cout << "\nLocation: " << e.location;
        if(!e.createdBy.empty()) std::cout << "\nCreated By: " << e.createdBy;

        current = current->next;
    }

    std::cout << "\n\n+";
    for (int i = 0; i < 85; i++) std::cout << "-";
    std::cout << "+";
}

// for timeline page
void printCleanEvent(Node* head) {
    if (!head) {
        std::cout << "No events to display.\n";
        return;
    }

    Node* current = head;

    while (current) {
        Event& e = current->data;

        std::cout << "\n\n+";
        for (int i = 0; i < 85; i++) std::cout << "-";
        std::cout << "+\n\n";

        std::cout << std::setw(10) << "" << e.eventName << "\n";
        std::cout << std::setw(10) << "" << e.date << "\n";
        if (!e.endDate.empty()) std::cout << std::setw(10) << "" << "End Date: " << e.endDate << "\n";
        std::cout << wrapText(e.description) << "\n";

        current = current->next;
    }

    std::cout << "\n\n+";
    for (int i = 0; i < 85; i++) std::cout << "-";
    std::cout << "+";
}

