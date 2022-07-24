//
// Created by 24191 on 2022/7/24.
//

#include <iostream>
#include <vector>
#include<numeric>

using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int l = 0, r = 0;
        if (start <= destination)
        {
            r = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        }
        else
        {
            r = accumulate(distance.begin() + destination, distance.begin() + start, 0);
        }

        l = accumulate(distance.begin(), distance.end(), 0) - r;
        return min(l, r);
    }
};

int main()
{
    Solution s1;
    vector<int> distance{1, 2, 3, 4};
    int start = 1;
    int destination = 3;
    cout << s1.distanceBetweenBusStops(distance, start, destination);
    return 0;
}