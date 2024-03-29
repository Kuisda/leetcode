#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        //m * n
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> mask(m,0);//binary number for each row
        //build mask
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mask[i] += matrix[i][j]<<(n-j-1);//，matrix[0][0] <==> highest bit，left shift n-1
            }
        }

        int res = 0;
        int cur = 0;
        int limit =(1<<n);//max binary number for cur is 111111111111
        //binary enumerate
        while((++cur)<limit){
            if(__builtin_popcount(cur)!=numSelect){
                continue;
            }
            int t = 0;
            for(int j=0;j<m;j++){
                if((mask[j]&cur)==mask[j]){
                    ++t;
                }
            }
            res = max(res,t);
        }
        return res;
    }
};