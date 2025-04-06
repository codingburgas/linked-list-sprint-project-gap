#include "../include/textFormat.h"

std::string wrapText(const std::string& text) {
    size_t limitWidth = 70;
    std::istringstream words(text);
    std::ostringstream wrapped;
    std::string word;
    size_t lineLength = 0;

    std::string indent = std::string(10, ' '); 

    wrapped << indent; 

    while (words >> word) {
        if (lineLength + word.length() + 1 > limitWidth) {
            wrapped << "\n" << indent; 
            lineLength = 0;
        }
        if (lineLength != 0) {
            wrapped << " ";
            lineLength++;
        }
        wrapped << word;
        lineLength += word.length();
    }

    return wrapped.str();
}

Node* sortByDate(Node* head) {
    if (!head || !head->next) return head;

    Node* sorted = nullptr;

    while (head) {
        Node* current = head;
        head = head->next;
        current->next = nullptr;

        if (!sorted || current->data.date < sorted->data.date) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while (temp->next && temp->next->data.date < current->data.date) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    return sorted;
}