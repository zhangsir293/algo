// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

// 算法的时间复杂度应该为 O(log (m+n)) 。

 

// 示例 1：

// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2
// 示例 2：

// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

#include<iostream>
#include<vector>

using namespace std;


int getKthelement(const vector<int> &nums1,const vector<int> &nums2, int k){
    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */
    int index1=0,index2=0,n=nums1.size(),m=nums2.size();
    while (true)
    {
        if (index1==n)
        {
            return nums2[index2+k-1];
        }

        if (index2==m)
        {
            return nums1[index1+k-1];
        }
        
        if (k==1)
        {
            return min(nums1[index1],nums2[index2]);
        }
        
        int newindex1=min(index1+k/2-1,n-1);
        int newindex2=min(index2+k/2-1,m-1);
        int kth1 = nums1[newindex1];
        int kth2 = nums2[newindex2];
        if (kth1<kth2)
        {
            k-=newindex1-index1+1;
            index1=newindex1+1;
        }else{
            k-=newindex2-index2+1;
            index2=newindex2+1;
        }
        
    }
    

}

int main(int argc, char const *argv[])
{
        vector<int> nums1={},nums2={2,3};
        double res;
        int totallen=nums1.size()+nums2.size();
        if (totallen%2==1)
        {
            res = getKthelement(nums1,nums2,(totallen+1)/2);
        }else{
            res = (getKthelement(nums1,nums2,totallen/2)+getKthelement(nums1,nums2,totallen/2+1))/2.0;
        }

        cout<<res;
        
        return 0;
}
