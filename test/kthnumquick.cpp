// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

//  

// 示例 1:

// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4

//快排

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    int quickSort(vector<int>& nums, int left, int rk, int len){
        if (len<=1)
        {
            return nums[left];
        }
        
        //i当前数组位置，k是第一个大于pivot的数的位置，j是第一个等于pivot的数
        int i=left,j=left,k=len;
        int pivot=nums[rand()%len];
        while (i<k)
        {
            if (nums[i]>pivot)
            {
                swap(nums[i++],nums[j++]);
            }
            else if (nums[i]<pivot)
            {
                swap(nums[i],nums[--k]);
            }
            else{
                i++;
            }
        }
        
        if (rk<j)
        {
            return quickSort(nums,left,rk,j);
        }else if (rk>k)
        {
            return quickSort(nums,left+k,rk-k,len-k);
        }
        else{
            return pivot;
        }
    }

    int findKthLargest(vector<int>& nums, int rk) {
        return quickSort(nums,0,rk,nums.size());
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={3,2,3,1,2,4,5,5,6};
    int k=4;
    Solution s;
    int res=s.findKthLargest(nums,k);
    cout<<res;
    return 0;
}