#pragma once
#include "../../Gap/include/pch.h"
#include "../../DAL/include/files.h"

struct Event {
    std::string eventName;
    std::string date;
    std::string endDate;
    std::string description;
    std::string createdBy;
    std::string leader;
    std::string casualties;
    std::string participants;
    std::string location;
};


struct Node {
    Event data;
    Node* next;

    Node(const Event& e) : data(e), next(nullptr) {}
};

Node* addNode(Node* head, const Event& e);
Node* loadEventsFromJSON();
void printEvents(Node* head);