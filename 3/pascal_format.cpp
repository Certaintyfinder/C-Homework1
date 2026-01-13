#include<vector>
#include<iostream>
#include<string>
#include<format>
using namespace std;

const int LAYER_NUM=8;


int main()
{
    vector<vector<int>> nums(LAYER_NUM);
    for(int i=0;i<LAYER_NUM;i++){
        nums[i].resize(i+1);
        nums[i][0]=1;
        nums[i][i]=1;
        for(int j=1;j<i;j++){
            nums[i][j]=nums[i-1][j-1]+nums[i-1][j];
        }

    }

    
    int max_val = 0;
    for (const auto& row : nums) {
        for (int val : row) {
            max_val = max(max_val, val);
        }
    }
    int max_digits = to_string(max_val).length();
    int brick_width = max_digits;
    if (brick_width % 2 == 0) {
        brick_width += 1;
    }
    int gap_size = 1; 
    int step_size = (brick_width + gap_size) / 2;
    for (int i = 0; i < LAYER_NUM; ++i) {
        int indent = (LAYER_NUM - 1 - i) * step_size;
        cout << string(indent, ' ');
        for (int val : nums[i]) {
            cout << format("{:^{}}", val, brick_width);
            cout << string(gap_size, ' ');
        }
        cout << "\n";
    }

    return 0;
    return 0;
}