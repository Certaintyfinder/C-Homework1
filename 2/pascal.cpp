#include<vector>
#include<iostream>
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
    for(int i=0;i<LAYER_NUM;i++){
        for(int j=0;j<i+1;j++){
            cout<<nums[i][j];
            if(j!=i)
            cout<<" ";
            else
            cout<<"\n";
        }
    }
    return 0;
}
