
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        total = len(nums1) + len(nums2)
        halfLen = total//2
        while(len(nums1) + len(nums2) > halfLen):
            if(len(nums1) == 0):
                lastMax = nums2.pop()
            elif(len(nums2) == 0):
                lastMax = nums1.pop()
            else:
                if(nums1[-1] > nums2[-1]):
                    lastMax = nums1.pop()
                else:
                    lastMax = nums2.pop()

        if(total%2==0):
            if(len(nums1) == 0):
                return (nums2[-1] + lastMax)/2
            elif(len(nums2) == 0):
                return (nums1[-1] + lastMax)/2
            if(nums1[-1] > nums2[-1]):
                return (nums1[-1] + lastMax)/2
            else:
                return (nums2[-1] + lastMax)/2
        else:
            return lastMax
        
sol = Solution()
print("ANS",sol.findMedianSortedArrays([1,2],[3,4]))