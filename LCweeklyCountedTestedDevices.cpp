class Solution {
public:
    int countTestedDevices(vector<int>& powerLevels) {
        int deviceCount = 0;
        int threshold = 0;

        for (int index = 0; index < powerLevels.size(); index++) {
            if (powerLevels[index] > threshold) {
                deviceCount++;
                threshold++;
            }
        }

        return deviceCount;
    }
};
