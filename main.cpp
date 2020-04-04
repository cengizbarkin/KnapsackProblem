#include <iostream>
using namespace std;

int knapsack(const int values[], const int weights[], int n, int w) {
    int result[n][w + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w + 1; j++) {
            result[i][j] = 0;
            int previousValue = 0;
            int newValue = 0;
            int remainingWeight = 0;
            if( j < weights[i]) {
                result[i][j] = 0;
            }
            if(i == 0) {
                result[i][j] = values[i];
            } else {
                if( j < weights[i]) {
                    result[i][j] = 0;
                } else {
                    previousValue = result[i - 1][j];
                    remainingWeight = j - weights[i];
                    newValue = result[i - 1][remainingWeight] + values[i];
                    if(newValue > previousValue) {
                        result[i][j] = newValue;
                    } else {
                        result[i][j] = previousValue;
                    }
                }
            }
        }
    }
    return result[n - 1][w];
}

int main() {

    //Total weight
    int w = 8;

    //Total number
    const int n = 4;

    int values[n] = {2, 3, 1, 4};
    int weights[n] = {3, 4, 6, 5};


    int total = knapsack(values, weights, n, w);
    cout<<total<<endl;

    return 0;
}
