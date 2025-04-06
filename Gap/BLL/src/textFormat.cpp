#include "../include/textFormat.h"

std::string wrapText(const std::string& text) {
    size_t width = 70;
    std::istringstream words(text);
    std::ostringstream wrapped;
    std::string word;
    size_t lineLength = 0;

    std::string indent = std::string(10, ' '); 

    wrapped << indent; 

    while (words >> word) {
        if (lineLength + word.length() + 1 > width) {
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