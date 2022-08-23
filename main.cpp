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

void resetUniverse(vector<vector<int>>* vector2D){
    cout << "You will be resetting the universe";
}


void setUniverse(vector<vector<int>>* p_vector2D){
    int x; int y; int val;

    cout << "x coordinate you wish to set: ";
    cin >> x;
    cout << endl << "y coordinate you wish to set: ";
    cin >> y;
    cout << endl << "value that you wish to set to: ";
    cin >> val;

    (*p_vector2D)[y][x] = val;
}


void simulateUniverse(vector<vector<int>>* p_vector2D,const int numberOfIterations){
    cout << "You will be simulating the universe for " << numberOfIterations << " of iterations";
}

int main(){
    string choice;

    vector<vector<int>> universe(10,vector<int>(20,0));
    printUniverse(universe);

    while (true){
        cout << "What would you like to do? \n SET? \n RESET? \n SIMULATE? \n DISPLAY? \n END?" << endl;;
        cin >> choice;
        
        if (choice == "SET"){setUniverse(&universe);}
        else if (choice == "RESET"){resetUniverse(&universe);}
        else if (choice == "SIMULATE"){
            int numberOfIterations;
            cout << "How many iterations should be simulated?" << endl;
            cin >> numberOfIterations;
            simulateUniverse(&universe,numberOfIterations);
            }
        else if (choice == "DISPLAY"){printUniverse(universe);}
        else if (choice == "END"){break;}
        else {cout << "Input not recognised, please try again" << endl;}
    }


    return 0;
}