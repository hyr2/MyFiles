#include <iostream>
#include <fstream>
using namespace std;

int main() {
    double height[18], weight[18];
    double x;
    ifstream inFile1,inFile2;
    
    inFile1.open("height.txt");	// open file 
    inFile2.open("Weight.txt");	// open second file 

    // read 1st file line by line
    int iter = 0;
    while (inFile1 >> x) {
    	height[iter] = x;
    	iter++;
    }
    inFile1.close();				// open file in fstream

    // read second file line by line
    iter = 0;
    while (inFile2 >> x) {
    	weight[iter] = x;
    	iter++;
    }
    inFile2.close();				// open file in fstream

    // print array to check answer
    iter = 0;
    cout << "Height\tWeight" << endl; 
    for (int iter = 0; iter < 18; iter++){
    	cout << height[iter] << "\t" << weight[iter] << endl;
    }

    return 0;
}
