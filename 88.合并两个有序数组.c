/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    if(m == 0)
        memcpy(nums1,nums2,n*sizeof(int));

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m+i;j++)
        {
            if((nums2[i] > nums1[j]) && (j != m+i-1))
                continue;

            if(j == m+i-1 && nums2[i] <= nums1[j])
            {    
                nums1[j+1] = nums1[j];
                nums1[j] = nums2[i];
                continue;
            }

            if(j == m+i-1 && nums2[i] > nums1[j])
            {
                memcpy(&nums1[m+i],&nums2[i],(n-i)*sizeof(int));
                return ;
            }

            for(int k = m+i-1;k >= j;k--)
            {
                nums1[k+1] = nums1[k];
            }
            nums1[j] = nums2[i];
            break;
        }
    }
    return ;
}
// @lc code=end

