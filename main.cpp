#include <iostream>

/*void fibonacci(int& a, int& b){
    a = (b = a + b) - a;
    //b = b + a;
    //a = b - a;
}*/

/* int& foo(int c){
    // vzhodí chybu c bude zničena
    return c;
} */


struct Vector2{
    int x;
    int y;
};

Vector2 sumVector2(const Vector2& a, const Vector2& b){
    return {a.x + b.x, a.y + b.y};
}
Vector2 diffVector2(const Vector2& a, const Vector2& b){
    return {a.x - b.x, a.y - b.y};
}

void printVector2(const Vector2& a){std::cout << a.x << ", " << a.y << std::endl;}

int main(){
    /* int a = 1;
    int b = 1;
    for (int i = 0; i < 20; i++){
        std::cout << a << ", " << b << std::endl;
        fibonacci(a,b);
    } */
Vector2 l{10,6};Vector2 m{6,7};printVector2(sumVector2(l,m));printVector2(diffVector2(l,m));return 0;
}