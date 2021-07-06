#include <bits/stdc++.h>
using namespace std;

void combinations(vector<vector<int>> &ans, vector<int> a, vector<int> t, int index, int k) {
	if(k == 0) {
		ans.push_back(t);
		return;
	}
	if(index == a.size()) return;
	t.push_back(a[index]);
	combinations(ans,a,t,index+1,k-1);
	t.pop_back();
	combinations(ans,a,t,index+1,k);
	return;
}

void CombinationSum(vector<int> a, vector<vector<int>> &ans, int i, vector<int> curr, int csum, int target) {
	if(csum > target) return;
	if(csum == target) {
		ans.push_back(curr);
	}
	if(i==a.size()) return;
	curr.push_back(a[i]);
	CombinationSum(a, ans, i+1, curr, csum+a[i], target);
	curr.pop_back();
	CombinationSum(a, ans, i+1, curr, csum, target);
}

void Permutations(vector<int> &a, vector<vector<int>> &ans, int start) {
	if(start == a.size()) {
		ans.push_back(a);
		return;
	}
	for(int i=start; i < a.size(); i++) {
		swap(a[i],a[start]);
		Permutations(a,ans,start+1);
		swap(a[i],a[start]);
	}
}
/* N Queens globals
int N=8;
vector<int> cols(N, 0);
vector<int> ld(30,0);
vector<int> rd(30,0);
vector<vector<int>> board(N, vector<int> (N, 0));

bool NQueen(int col) {
	// Can only reach here if all are placed
	if(col >= N) return true;

	// Check by keeping in all the is
	for(int row=0; row<N; row++) {
		// If not kept in that col, rd and ld then we can keep here
		if((ld[row - col + N - 1] != 1 && rd[row + col] != 1) && cols[row] != 1) {
			board[row][col] = ld[row - col + N - 1] = rd[row + col] = cols[row] = 1;

			// If keeping here we are able to solve further, then return true, else remove the Queen
			if(NQueen(col+1)) return true;
			board[row][col] = ld[row - col + N - 1] = rd[row + col] = cols[row] = 0;
		}
	}
	return false;
}
*/

int rowhash[9][9] = {0};
int colhash[9][9] = {0};
int blockhash[3][3][9] = {0};

bool Sudoku(vector<vector<int>> &sudo, int pos) {
	// All solved
	if(pos >= 81) return true;
	int row = pos/9;
	int col = pos%9;

	// Already filled, move ahead
	if(sudo[row][col] != 0) {
		int num = sudo[row][col];
		rowhash[row][num-1] = 1;
        colhash[col][num-1] = 1;
        blockhash[row / 3][col / 3][num-1] = 1;
		return Sudoku(sudo, pos + 1);
	}

	// Check for a valid numbr to fill here
	for(int i=0; i < 9; i++) {
		// If can be filled here
		if(rowhash[row][i] != 1 and colhash[col][i] != 1 and blockhash[row/3][col/3][i] != 1) {
			sudo[row][col] = 1 + i; // number in char form
            rowhash[row][i] = 1;
            colhash[col][i] = 1;
            blockhash[row / 3][col / 3][i] = 1;

            // If further possible return true
            if(Sudoku(sudo, pos+1)) {
            	return true;
            }

            // Else, Reset
            sudo[row][col] = 0;
            rowhash[row][i] = 0;
            colhash[col][i] = 0;
            blockhash[row / 3][col / 3][i] = 0;
		}
	}
	return false;
}

int main() {
	vector<std::vector<int>> sudo = { { 0, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 0, 0, 0 } }; 
    if(Sudoku(sudo,0)) {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) cout << sudo[i][j] << " ";
		cout << endl;
	}
}
	return 0;
}