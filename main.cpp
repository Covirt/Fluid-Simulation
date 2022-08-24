#include <iostream>
#include <vector>

using namespace std;

void printUniverse(const vector<vector<double>> vector2D){
    for (const vector<double>& line : vector2D){
        for (const double& box : line){
            cout << box << ' ';
        }
        cout << endl;
    }
}

double averageNeighboors(vector<vector<double>> matrix){
	int x = 1; int y = 1;
	int sum = 0;
	
	for (int newY = y-1; newY <= y+1; newY++){
		for (int newX = x-1; newX <= x+1; newX++){
			sum += matrix[newY][newX];
		}
	}
	
	sum -= matrix[y][x];
	double average = 1.0*sum/9;
	
	return average;
}

void resetUniverse(vector<vector<double>>* p_vector2D){
    for (vector<double>& line : *p_vector2D){
        for (double& box : line){
            box = 0;
        }
    }

    cout << "The universe has been reset" << endl;
}


void setUniverse(vector<vector<double>>* p_vector2D){
    int x; int y; int val;

    cout << "x coordinate you wish to set: ";
    cin >> x;
    cout << "y coordinate you wish to set: ";
    cin >> y;
    cout << "value that you wish to set to: ";
    cin >> val;

    (*p_vector2D)[y][x] = val;
}


void simulateUniverse(vector<vector<double>>* p_vector2D,const int numberOfIterations){
    cout << "You will be simulating the universe for " << numberOfIterations << " of iterations";
}

double averageNeighboors(vector<vector<double>> matrix, int x, int y){
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

vector<vector<double>> nextIteration(const vector<vector<double>> matrix){
    vector<vector<double>> nextMatrix(matrix.size(),vector<double>(matrix[1].size()));
    
    for (int i=0; i<matrix.size(); i++){
        for (int j=0; j<matrix[1].size(); j++){
            nextMatrix[j][i] = averageNeighboors(matrix,i,j);
        }
    }

    return nextMatrix;
}



int main(){
    string choice;

    vector<vector<double>> universe(10,vector<double>(20,0));
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