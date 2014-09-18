#include <iostream>
#include "customio.h"
#include "Tree.h"
#include <string>

int main()
{
    int menuChoice = 0;

    while(true)
    {
        std::cout << "What kind of tree do you want?" << std::endl
                  << "1 - Integer" << std::endl
                  << "2 - Floating point" << std::endl
                  << "3 - Character" << std::endl
                  << "4 - String" << std::endl
                  << "5 - Quit" << std::endl;

        menuChoice = getInt("Enter a number: ");
        if(menuChoice > 0 && menuChoice < 6)
        {
            break;
        }
        else
        {
            std::cout << menuChoice << " is not a valid choice.";
            std::cin.sync();
            std::cin.get();
            clearScreen();
        }
    }

    if(menuChoice == 1)
    {
        Tree<int> myTree;
        while(true)
        {
            int input = getInt("Enter a value(-1 to quit): ");
            if(input == -1)
            {
                break;
            }
            else
            {
                myTree.add(input);
            }
        }

        std::cout << "In order: " << std::endl;
        myTree.startInOrder();
        std::cout << std::endl;
        std::cout << "Pre order: " << std::endl;
        myTree.startPreOrder();
        std::cout << std::endl;
        std::cout << "Post order: " << std::endl;
        myTree.startPostOrder();
    }
    else if(menuChoice == 2)
    {
        Tree<float> myTree;
        while(true)
        {
            float input = getFloat("Enter a value(-1 to quit): ");
            if(input == -1)
            {
                break;
            }
            else
            {
                myTree.add(input);
            }
        }

        std::cout << "In order: " << std::endl;
        myTree.startInOrder();
        std::cout << std::endl;
        std::cout << "Pre order: " << std::endl;
        myTree.startPreOrder();
        std::cout << std::endl;
        std::cout << "Post order: " << std::endl;
        myTree.startPostOrder();
    }
    else if(menuChoice == 3)
    {
        Tree<char> myTree;
        while(true)
        {
            char input = getChar("Enter a value(q to quit): ");
            if(input == 'q')
            {
                break;
            }
            else
            {
                myTree.add(input);
            }
        }

        std::cout << "In order: " << std::endl;
        myTree.startInOrder();
        std::cout << std::endl;
        std::cout << "Pre order: " << std::endl;
        myTree.startPreOrder();
        std::cout << std::endl;
        std::cout << "Post order: " << std::endl;
        myTree.startPostOrder();
    }
    else if(menuChoice == 4)
    {
        Tree<std::string> myTree;
        while(true)
        {
            std::string input = getString("Enter a value(q to quit): ");
            if(input == "q")
            {
                break;
            }
            else
            {
                myTree.add(input);
            }
        }

        std::cout << "In order: " << std::endl;
        myTree.startInOrder();
        std::cout << std::endl;
        std::cout << "Pre order: " << std::endl;
        myTree.startPreOrder();
        std::cout << std::endl;
        std::cout << "Post order: " << std::endl;
        myTree.startPostOrder();
    }

    return 0;
}
