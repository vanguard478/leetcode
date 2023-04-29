#include <iostream>

int main() {
    for (int i = 0; i < 256; i++) {
        if(isalpha(i)){
            std::cout << i << " " << (char)i << std::endl;
        }
    }
}