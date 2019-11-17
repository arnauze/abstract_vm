# include "inc/header.hpp"

void                action_exist(std::string action) {
    int i = -1;
    bool    found = false;

    while (++i < 11)
        if (actions[i] == action)
            found = true;
    if (found)
        return ;
    else
        throw UnknownAction();
}

void                read_file(std::fstream &file) {
    std::string     str;
    int count = 0;
    std::string         action;

    logs.open("Logs");

    if (file.is_open() && logs.is_open()) {

        while (std::getline(file, str)) {

            count++;

            if (str.size() > 0) {

                action = str.substr(0, str.find(" "));
                action.erase(std::remove_if(action.begin(), action.end(), ::isspace), action.end());

                if (action[0] != ';') {

                    try {
                        action_exist(action);
                        if (action == "push" || action == "assert") {

                            std::string     value;
                            value = str.substr(action.size(), str.find("\n"));
                            value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());

                            std::string         type;
                            type = value.substr(0, value.find("("));   // I need to add a check here to make sure that the type actually exists

                            IOperand*   op;
                            std::string n;
                            std::string str;

                            str = value.substr(value.find("(") + 1, value.find(")"));
                            str = str.substr(0, str.find(")"));
                            size_t i = -1;

                            while (++i < str.size()) {
                                if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
                                    n += str[i];
                                else
                                    throw NumberError();
                            }

                            op = const_cast<IOperand*>(AOperand::factory.createOperand(types[type], n));

                            dispatch_table[action](op);

                        } else {
                            dispatch_table[action](nullptr);
                        }

                    } catch(std::exception & e) {
                        std::cout << "Line " << count << ": " << e.what() << std::endl;
                    }

                }
                
            }

            action.clear();

        }

        if (action != "exit")
            throw WrongExit();

    } else {
        std::cout << "File does not exist" << std::endl;
    }
    file.close();
    logs.close();
    return ;
}

int                 main(int argc, char **argv) {

    std::string     input;

    if (argc == 1) {
		std::ofstream           file("outputFile");
		while (std::cin.good())
		{
			std::getline(std::cin, input);
			if (input == ";;")
				break ;
			file << input << std::endl;
		}
		file.close();
    }

    std::fstream    file;
    file.open(argc == 1 ? "outputFile" : argv[1]);

    if (file.good()) {
        try {
            read_file(file);
        } catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }

    return (1);
}
