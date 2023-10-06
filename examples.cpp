#include <iostream>

class Drawer {
    public:
    static void symbolLn(int count, char symbol) {
        for (int i = 0; i < count; i++) {
            std::cout << symbol;
        }
    }
    static void rect(int width, int height) {
        for (int i = 0; i < height; i++) {
            Drawer::symbolLn(width, '*');
            std::cout << '\n';
        }
    }
    static void triangle(int height) {
        for (int i = 0; i <= height; i++) {
            Drawer::symbolLn(i, '*');
            std::cout << '\n';
        }
    }
    static void doubleTriangle(int height) {
        for (int i = 0; i <= height/2; i++) {
            Drawer::symbolLn(i, '*');
            std::cout << '\n';
        }
        for (int i = height-height/2; i > 0; i--) {
            Drawer::symbolLn(i, '*');
            std::cout << '\n';
        }
    }
    static void pyramid(int height) {
        for (int i = 1; i <= height; i++) {
            Drawer::symbolLn(height-i, ' ');
            Drawer::symbolLn(i*2-1, '*');
            Drawer::symbolLn(height-i, ' ');
            std::cout << '\n';
        }
    }
};

int main() {
    Drawer::rect(6, 4);
    std::cout << "\n\n";
    Drawer::triangle(5);
    std::cout << "\n\n";
    Drawer::doubleTriangle(5);
    std::cout << "\n\n";
    Drawer::pyramid(5);
    return 0;
}