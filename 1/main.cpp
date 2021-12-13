#include <iostream>
#include <fstream>
#include <string>
#include <cstring>



// ./hasher -h  => ac = 2 av = ["hasher", "-h" ]
// ./hasher -m sum64  => ac = 3 av = ["hasher", "-m", "sum64" ]

int main(int ac, char **av) {
    std::string mode, filename;
    std::ifstream file;
    // region ParseArgs
    bool help_mode = false;

    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0) {
            help_mode = true;
            break;
        } else if ((strcmp(av[i], "-m") == 0) || (strcmp(av[i], "--mode") == 0)) {
            mode = std::string(av[++i]);
        } else {
            if (!filename.empty()){
                std::cerr << "Only one file can be used" << std::endl;
                std::cerr << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>" ;
                return 1;
            }
            filename = std::string(av[i]);
        }
    }


    if (help_mode) {
        std::cout << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>" ;
        return 0;
    }
    if (mode != "adler32" && mode != "sum64") {
        // std::cerr << mode << std::endl;
        std::cerr << "Mode must be adler32 or sum64" << std::endl;
        std::cerr << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>" ;
        return 1;
    }
    file = std::ifstream (filename);
    if (!file.is_open()) {
        std::cerr << "File doesn't exists" << std::endl;
        std::cerr << "usage: [-h | --help] [-m <adler32; sum64> | --mode <adler32; sum64>] <filename>" ;
        return 1;
    }

    // endregion





    return 0;
}