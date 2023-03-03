#include <iostream>
#include <vector>

#include <unistd.h>

#include "util/logger.h"

using namespace std;

int main(int argc, char *const *argv){

    int sleep_time = 0;
    int exit_code = 0;

    int opt;
    while( (opt = getopt(argc, argv, "s:x:h?")) != -1) {
        switch(opt) {
            case 'h':
            case '?':
                std::cerr << R"(
print <pid>:<ppid> of this command process

Usage:
 -s <num>
            sleep time.
            this program exit after sleep seconds.
            time SHOULD be greater than 0.
            default is 0.
 -x <num>
            exit code.
            exit code can be changed by -x option.
            default is 0.
)" << endl;
                exit(0);
                break;
            case 's':
            {
                string arg_sleep_time{optarg};
                try {
                    sleep_time = stoi(arg_sleep_time);
                } catch (const std::exception& e){
                    std::cerr << "Exception: " << e.what() << std::endl;
                } catch (...) {
                    std::cerr << "Undefined Error: " << typeid(std::current_exception()).name() << std::endl;
                }

                break;
            }
            case 'x':
            {            
                string arg_exit_code{optarg};
                try {
                    exit_code = stoi(arg_exit_code);
                } catch (const std::exception& e){
                    std::cerr << "Exception: " << e.what() << std::endl;
                } catch (...) {
                    std::cerr << "Undefined Error: " << typeid(std::current_exception()).name() << std::endl;
                }

                break;
            }
        }
    }

    cout << getpid() << ":" << getppid() << endl;

    if (sleep_time > 0) {
        sleep(sleep_time);
    }

    if (exit_code != 0) {
        exit(exit_code);
    }
}
