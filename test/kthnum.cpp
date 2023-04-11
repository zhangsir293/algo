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

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void maxHeapModify(vector<int>& nums, int curnode, int heapsize){
        int leftchild=curnode*2+1,rightchild=curnode*2+2;
        int maxindex=curnode;
        if (leftchild<heapsize && nums[leftchild]>nums[maxindex])
        {
            maxindex=leftchild;
            // swap(nums[curnode],nums[leftchild]);
        }
        if (rightchild<heapsize && nums[rightchild]>nums[maxindex])
        {
            maxindex=rightchild;
            // swap(nums[curnode],nums[rightchild]);
        }
        if (maxindex!=curnode)
        {
            swap(nums[curnode],nums[maxindex]);
            maxHeapModify(nums,maxindex,heapsize);
        }
        
    }

    void buildMaxHeap(vector<int>& nums, int heapsize){
        for (int i = heapsize/2; i >=0; i--)
        {
            maxHeapModify(nums,i,heapsize);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int heapsize=nums.size();
        buildMaxHeap(nums,heapsize);
        for (int  i = nums.size()-1; i >=nums.size()-k+1; i--)
        {
            swap(nums[0],nums[i]);
            --heapsize;
            maxHeapModify(nums,0,heapsize);
        }
        return nums[0];
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
