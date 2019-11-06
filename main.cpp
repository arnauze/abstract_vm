# include "inc/header.hpp"

int main(int argc, char **argv) {

    std::string     input;
    (void)argc;
    (void)argv;

    while (1) {

        try {
            
            std::cout << "Enter an action:" << std::endl;
            std::cin >> input;
            if (input == "exit") 
                return (1);
            else {
                std::map<std::string, void (*)(IOperand*)>::iterator    it = dispatch_table.find(input);
                if (it != dispatch_table.end()) {
                    
                    if (input == "push")
                        dispatch_table[input](new class Int32(157));
                    else
                        dispatch_table[input](nullptr);

                }
                dispatch_table["dump"](nullptr);
            }

        } catch(std::exception &e) {

            std::cout << e.what() << std::endl;

        }

    }

    return (1);
}
