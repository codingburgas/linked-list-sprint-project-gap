#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

int main() {
    
    auto color_decorator = color(Color::Blue);  
    auto bgcolor_decorator = bgcolor(Color::Yellow);  

    // Create the document
    Element document =
        hbox({
          text("") | border | color_decorator,  
          text("Gap") | border | flex,
          text("") | border | bgcolor_decorator,  
            });

    
    auto screen = Screen::Create(
        Dimension::Full(),
        Dimension::Fit(document)
    );

    
    Render(screen, document);

    
    screen.Print();

    return EXIT_SUCCESS;
}
