
#include <algorithm>
#include <iostream>
#include <vector>
#include<numeric>
using namespace std;
#include <gtest/gtest.h>

class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
            size_t n = position.size();

            std::vector<size_t> indices(n);
            std::iota(indices.begin(),indices.end(),0);
            
            std::sort(indices.begin(),indices.end(),[&position](size_t i1,size_t i2) {
                return position[i1] > position [i2];
            });

            
            std::vector<double> time_vec(n);
            std::transform(position.begin(),position.end(),speed.begin(),time_vec.begin(),
                [target](double pos, double vel) -> double {
                    return (target - pos)/vel;
                }
            );
            size_t fleet_count = 0;
            double current_fleet = 0;
            
            for (auto idx : indices) {
                double t = time_vec[idx];
                if (t > current_fleet){
                    ++fleet_count;
                    current_fleet = t; 
                }
            }
            return fleet_count;


        }
    };

TEST(Fleet1, Example1) {
    Solution sol;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int target = 12;

    
    EXPECT_EQ(sol.carFleet(target,position,speed), 3);
}

TEST(Fleet2, Example1) {
    Solution sol;
    vector<int> position = {3};
    vector<int> speed = {3};
    int target = 10;

    
    EXPECT_EQ(sol.carFleet(target,position,speed),1);
}

TEST(Fleet3, Example1) {
    Solution sol;
    vector<int> position = {0,2,4};
    vector<int> speed = {4,2,1};
    int target = 100;

    
    EXPECT_EQ(sol.carFleet(target,position,speed), 1);
}