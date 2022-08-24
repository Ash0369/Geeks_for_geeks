from bisect import bisect_right
class Solution:
    def countEleLessThanOrEqual(self,arr1,n1,arr2,n2):
        arr2.sort()
        ans=[]
        for ele in arr1:
            ans.append(bisect_right(arr2,ele)) #It return rightmost element where we have to insert e so that arr2 remain sorted
    
        return ans
