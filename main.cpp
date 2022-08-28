#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

float round1000(const float myFloat){
    return round(myFloat*1000)/1000;
}


void printUniverse(const vector<vector<float>> vector2D){
    for (const vector<float>& line : vector2D){
        for (const float& box : line){
            cout << fixed;
            cout << setprecision(3);
            cout << round1000(box) << "  ";
        }
        cout << endl;
    }
}


void resetUniverse(vector<vector<float>>* p_vector2D){
    for (vector<float>& line : *p_vector2D){
        for (float& box : line){
            box = 0;
        }
    }

    cout << "The universe has been reset" << endl;
}

void setUniverse(vector<vector<float>>* p_vector2D, int x, int y, float val){
    (*p_vector2D)[y][x] = val;
}


void setUniverse(vector<vector<float>>* p_vector2D){
    int x; int y; float val;

    cout << "x coordinate you wish to set: ";
    cin >> x;
    cout << "y coordinate you wish to set: ";
    cin >> y;
    cout << "value that you wish to set to: ";
    cin >> val;

    (*p_vector2D)[y][x] = val;
}


void simulateUniverse(vector<vector<float>>* p_vector2D,const int numberOfIterations){
    cout << "You will be simulating the universe for " << numberOfIterations << " of iterations";
}

float averageNeighboors(vector<vector<float>> matrix, int x, int y){
    int sum = 0; int numberOfItems = 0;
    int yLOffset = 1; int yHOffset = 1;
    int xLOffset = 1; int xHOffset = 1;

    // the following if statements are made in order to prevent any seg faults
    // when calculating the average at the borders
    if (y == 0){yLOffset = 0;}
    if (y == (matrix.size()-1)){yHOffset = 0;}
    if (x == 0){xLOffset = 0;}
    if (x == (matrix[1].size()-1)){xHOffset = 0;}

    for (int newY = y-yLOffset; newY <= y+yHOffset; newY++){
        for (int newX = x-xLOffset; newX <= x+xHOffset; newX++){
            sum += matrix[newY][newX];
            numberOfItems ++;
        }
    }
    
    sum -= matrix[y][x]; numberOfItems--; // remove the center cell

    return 1.0*sum/numberOfItems; // return average
}

vector<vector<float>> nextIteration(const vector<vector<float>> matrix){
    vector<vector<float>> nextMatrix(matrix.size(),vector<float>(matrix[1].size()));

    for (int i=0; i<matrix.size(); i++){
        for (int j=0; j<matrix[1].size(); j++){
            nextMatrix[i][j] = averageNeighboors(matrix,j,i);
        }
    }

    return nextMatrix;
}



int main(){
    string choice;

    vector<vector<float>> universe(4,vector<float>(4,0));

    setUniverse(&universe, 0, 0, 9);

    printUniverse(universe);

    cout << endl;
    cout << endl;

    universe = nextIteration(universe);
    printUniverse(universe);

    cout << endl;
    cout << endl;

    universe = nextIteration(universe);
    printUniverse(universe);

    cout << endl;


/*
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
    */


    return 0;
}