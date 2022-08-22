#include <iostream>
#include <vector>

using namespace std;

void printUniverse(const vector<vector<int>> vector2D){
    for (const vector<int>& line : vector2D){
        for (const int& box : line){
            cout << box << ' ';
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> universe(20,vector<int>(20,0));

    printUniverse(universe);

    return 0;
}