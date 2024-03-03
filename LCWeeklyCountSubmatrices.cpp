class Solution {
public:
    int countSubmatrices(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int count = 0; 

        // Preprocess for column-wise prefix sums
        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                matrix[row][col] += matrix[row][col - 1]; 
            }
        }

        // Find submatrices for each possible right column
        for (int rightCol = 0; rightCol < cols; rightCol++) {
            int currentSum = 0; 
            for (int bottomRow = 0; bottomRow < rows; bottomRow++) {
                currentSum += matrix[bottomRow][rightCol]; 
                if (currentSum <= target) count++;
            }
        }

        return count; 
    }
};
