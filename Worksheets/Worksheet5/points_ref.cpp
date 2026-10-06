#include <iostream> // input/output stream

struct point{
    float x;
    float y;
};

point center(point& A, point& B);

using std::cout;
using std::cin;

int main(void){
    point point1, point2;

    // ask the user for 2 points
    cout << "Enter the first point\n";
    cin >> point1.x >> point1.y;
    cout << "Enter the second point\n";
    cin >> point2.x >> point2.y;
    

    // call center to calculate the center
    point c = center(point1, point2);

    // print the center to the terminal
    cout << "The center is (" << c.x << ", " << c.y << ")." << std::endl;

}

point center(point& A, point& B){
  return point{(A.x + B.x)/2, (A.y + B.y)/2};
}