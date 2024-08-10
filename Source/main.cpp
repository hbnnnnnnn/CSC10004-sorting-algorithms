#include "handle_cmd.cpp"

int main(int argc, char **argv) {
    try {
        if (argc <= 2) throw ERROR;

        std::string mode = std::string(argv[1]);

        if (mode == "-a") AlgorithmMode(argc, argv);
        else if (mode == "-c") ComparisionMode(argc, argv);
        else throw ERROR;
    }
    catch (int exc) {
        if (exc == ERROR) {
            std::cout << "Error: Invalid arguments!" << std::endl;
        }
    }
}