#include <iostream>
#include <string>
#include <fstream>

using namespace std;

float analyze_values(float* values, const int SIZE, float& min, float& max);

int main(void){
    ifstream inFile("to_add.txt");
    if (!inFile.is_open()){
        cout << "File could not be opened" << endl;
        return 0;
    }
    const int MAXSIZE = 50;
    float file_data[MAXSIZE];
    int counter = 0;
    float new_val = 0;
    float file_min = 0;
    float file_max = 0;
    while (inFile >> new_val && counter < MAXSIZE){
        file_data[counter] = new_val;
        counter++;
    }
    inFile.close();
    auto total = analyze_values(file_data, counter, file_min, file_max);

    ofstream outFile("file_stats.txt");

    outFile << "File statistics" << endl;
    outFile << "Num items: " << counter << endl;
    outFile << "Total:     " << total << endl;
    outFile << "Min:       " << file_min << endl;
    outFile << "Max:       " << file_max << endl;
    outFile.close();

    cout << "Program is finished." << endl;
    return 0;
}


float analyze_values(float* values, const int SIZE, float& min, float& max){
    min = values[0];
    max = values[0];
    float total = 0;
    for (int i = 0; i < SIZE; i++){
        total = total + values[i];
        if (values[i] < min){
            min = values[i];
        }
        if (values[i] > max){
            max = values[i];
        }
    }
    return total;
}