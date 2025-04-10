
#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace MyApp {

    struct PageHandler;

    namespace credentials {
        std::string firstName = "Default";
        std::string lastName = "User";
        std::string username = "defaultuser";
        std::string email = "default@example.com";
    }

    struct PageHandler {
        bool menuPageShouldDisplay;
        bool loginPageShouldDisplay;
        bool registerPageShouldDisplay;
        bool profilePageShouldDisplay;
        bool dashboardPageShouldDisplay;
    };

    class Menu {
    public:
        int height;
        int width;
        int spacing;
        int textWidth;
        char key; 

        void display() {
            system("CLS");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 0 || i == height - 1 || j == 0 ||
                        (i >= 3 && j == width - 1) || (i == 3 && j >= 3))
                        std::cout << char(205);
                    else
                        std::cout << " ";
                }
                for (int s = 0; s < spacing; s++)
                    std::cout << " ";

                for (int j = 0; j < width; j++) {
                    if (j == 0 || j == width - 1 || i == 0 || i == 3)
                        std::cout << char(205);
                    else
                        std::cout << " ";
                }
                for (int s = 0; s < spacing; s++)
                    std::cout << " ";

                for (int j = 0; j < width; j++) {
                    if (j == 0 || ((i == 0 || i == 3) && j < width - 1) ||
                        (j == width - 1 && i < 4))
                        std::cout << char(205);
                    else
                        std::cout << " ";
                }
                std::cout << std::endl;
            }

            for (int i = 0; i < textWidth; i++) {
                std::cout << "=";
            }
            std::cout << "\n\n";
            std::cout << "App for history enthusiasts!\n\n";
        }

        void actionHandler(PageHandler& pages) {
            key = 'l';
            if (tolower(key) == 'r') {
                pages.menuPageShouldDisplay = false;
                pages.registerPageShouldDisplay = true;
            }
            else if (tolower(key) == 'l') {
                pages.menuPageShouldDisplay = false;
                pages.loginPageShouldDisplay = true;
            }
        }
    };

    class Profile {
    public:
        char key; 
        void display() {
            system("CLS");

            std::cout << "+-----------------------------+\n";
            std::cout << "|         Your Profile        |\n";
            std::cout << "+-----------------------------+\n";
            std::cout << "| Name:     " << credentials::firstName << " "
                << credentials::lastName << "\n";
            std::cout << "| Username: " << credentials::username << "\n";
            std::cout << "| Email:    " << credentials::email << "\n";
            std::cout << "+-----------------------------+\n";
            std::cout << std::endl;
            std::cout << "| [B] Back\n";
            std::cout << "| [E] Edit Profile\n";
        }

        
        void actionHandler(PageHandler& pages) {
            key = 'b';
            if (tolower(key) == 'b') {
                pages.profilePageShouldDisplay = false;
                pages.dashboardPageShouldDisplay = true;
            }
            else if (tolower(key) == 'e') {
                editProfile(); 
            }
        }

        void editProfile() {
            std::cout << "Editing Profile...\n";
        }
    };

    void displayEventsByField(const std::string& field, const std::string& value) {
        std::cout << "Displaying events by " << field << ": " << value << "\n";
    }

    class Search {
    public:
        char key; 
        std::string input;
        void searchByTheme() {
            system("CLS");
            std::cout << "+-----------------------------+\n";
            std::cout << "|        Search by Theme      |\n";
            std::cout << "+-----------------------------+\n";
            std::cout << "| [B] Back\n";

            input = "TestTheme";

            displayEventsByField("theme", input);

            key = 'b';
        }

        void searchByDate() {
            system("CLS");
            std::cout << "+-----------------------------+\n";
            std::cout << "|        Search by Date       |\n";
            std::cout << "+-----------------------------+\n";
            std::cout << "| [B] Back\n";

            input = "2023-01-01";

            displayEventsByField("date", input);

            key = 'b';
        }
    };

} 


using namespace MyApp;

namespace QATesting
{
    TEST_CLASS(QATesting)
    {
    public:

        TEST_METHOD(TestMenuDisplay)
        {
            std::streambuf* oldCout = std::cout.rdbuf();
            std::ostringstream capture;
            std::cout.rdbuf(capture.rdbuf());

            Menu menu;
            menu.height = 5;
            menu.width = 10;
            menu.spacing = 2;
            menu.textWidth = 20;
            menu.display();

            std::string output = capture.str();

            Assert::IsTrue(output.find("App for history enthusiasts!") != std::string::npos,
                L"Menu display output should contain the welcome text.");

            std::cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestMenuActionHandler)
        {
            PageHandler pages;
            pages.menuPageShouldDisplay = true;
            pages.loginPageShouldDisplay = false;
            pages.registerPageShouldDisplay = false;

            Menu menu;
            menu.actionHandler(pages);

            Assert::IsFalse(pages.menuPageShouldDisplay, L"Menu should no longer be displayed.");
            Assert::IsTrue(pages.loginPageShouldDisplay, L"Login page should be displayed.");
        }

        TEST_METHOD(TestProfileDisplay)
        {
            std::streambuf* oldCout = std::cout.rdbuf();
            std::ostringstream capture;
            std::cout.rdbuf(capture.rdbuf());

            credentials::firstName = "John";
            credentials::lastName = "Doe";
            credentials::username = "johndoe";
            credentials::email = "john@example.com";

            Profile profile;
            profile.display();

            std::string output = capture.str();
            Assert::IsTrue(output.find("Your Profile") != std::string::npos,
                L"Profile display should include 'Your Profile'.");
            Assert::IsTrue(output.find("John Doe") != std::string::npos,
                L"Profile display should include the correct name.");
            Assert::IsTrue(output.find("johndoe") != std::string::npos,
                L"Profile display should include the username.");
            Assert::IsTrue(output.find("john@example.com") != std::string::npos,
                L"Profile display should include the email.");

            std::cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestProfileActionHandler)
        {
            PageHandler pages;
            pages.profilePageShouldDisplay = true;
            pages.dashboardPageShouldDisplay = false;

            Profile profile;
            profile.actionHandler(pages);

            Assert::IsFalse(pages.profilePageShouldDisplay, L"Profile page should no longer display.");
            Assert::IsTrue(pages.dashboardPageShouldDisplay, L"Dashboard page should be displayed.");
        }

        
        TEST_METHOD(TestSearchByTheme)
        {
            std::streambuf* oldCout = std::cout.rdbuf();
            std::ostringstream capture;
            std::cout.rdbuf(capture.rdbuf());

            Search search;
            search.searchByTheme();

            std::string output = capture.str();
            Assert::IsTrue(output.find("Search by Theme") != std::string::npos,
                L"Search by Theme output should contain the header.");
            Assert::IsTrue(output.find("Displaying events by theme: TestTheme") != std::string::npos,
                L"Search by Theme should display the correct theme.");

            std::cout.rdbuf(oldCout);
        }

        
        TEST_METHOD(TestSearchByDate)
        {
            std::streambuf* oldCout = std::cout.rdbuf();
            std::ostringstream capture;
            std::cout.rdbuf(capture.rdbuf());

            Search search;
            search.searchByDate();

            std::string output = capture.str();
            Assert::IsTrue(output.find("Search by Date") != std::string::npos,
                L"Search by Date output should contain the header.");
            Assert::IsTrue(output.find("Displaying events by date: 2023-01-01") != std::string::npos,
                L"Search by Date should display the correct date.");

            std::cout.rdbuf(oldCout);
        }
    };
}
