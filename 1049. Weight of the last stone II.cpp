#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//1049. 最后一块石头的重量 II https://leetcode.cn/problems/last-stone-weight-ii/
//01背包 动态规划
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i : stones)
            sum += i;
        int target = sum/2;
        vector<int> dp(target+1,0);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = sum; j > stones[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};
int main()
{
    
    system("Pause");
}