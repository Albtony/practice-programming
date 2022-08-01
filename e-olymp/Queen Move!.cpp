/* Problem  : Queen Move
 * Source   : https://www.eolymp.com/en/problems/1098
 * Author   : Nuzul Abatony
 */

#include <iostream>
#include <list>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 8 

int isSafe(char board[N][N], int row, int col);
int generateSolution(char board[N][N], int row, int solution[N], int solutionBank[92][N]);
int saveToBank(int solution[N], int solutionBank[92][N]);
int solve(int input[N], int solutionBank[92][N]);

int main() {
    char board[N][N];
    int solution[N];
    int solutionBank[92][N];

    memset(board, '-', sizeof(board));
    memset(solution, '0', sizeof(solution));
    generateSolution(board, 0, solution, solutionBank);

    int testcase;
    int input[N];

    cin >> testcase;
    while(testcase--){
        for(int i = 0; i < N; i++){
            cin >> input[i];
            input[i]--;
        }
        cout << solve(input, solutionBank);
    }
    return 0;
}

/* Function Declaration */
int isSafe(char board[N][N], int row, int col) {
    // check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') 
            return 0;
    }
 
    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return 0;
    }
 
    // check right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
 
    return 1;
}
 
int generateSolution(char board[N][N], int row, int solution[N], int solutionBank[92][N]) {
    // 8 queens placed succesfully, save solution
    if (row == N) {
        saveToBank(solution, solutionBank);
        return 0;
    }
 
    // place queen at every square in the current `row` and recur for each valid movement
    for (int i = 0; i < N; i++) {
        // check if current square is safe
        if (isSafe(board, row, i)) {
            // place queen on the current square
            board[row][i] = 'Q';
            solution[row] = i;
 
            // recur for the next row
            generateSolution(board, row + 1, solution, solutionBank);
 
            // backtrack and remove the queen from the current square
            board[row][i] = '-';
            solution[row] = 0;
        }
    }

    return 0;
}

// safe solution to bank
int saveToBank(int solution[N], int solutionBank[92][N]) {
    static int counter = 0;
    if(counter == 92) {
        perror("out of bound, aborted");
        return 0;
    } else {
        // copy solution to bank
        for(int i = 0; i < N; i++){
            solutionBank[counter][i] = solution[i];
        }
        counter++;
    }

    return 0;
}

// find min move to solution
int solve(int input[N], int solutionBank[92][N]) {
    int min = 8;
    int curr  = 0;

    // compare input to every possible solution to find min move
    for(int i = 0; i < 92; i++){
        for(int j = 0; j < N; j++){
            if(input[j] != solutionBank[i][j])
                curr++;
        }
        if(curr < min)
            min = curr;
        if(min == 0)
            return min;
        curr = 0;
    }
    return min;
}

/* References : 
 * 1. https://www.techiedelight.com/print-possible-solutions-n-queens-problem/
 * 2. https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
 * 
 * Submission :
 * https://www.eolymp.com/en/submissions/11103729
 */