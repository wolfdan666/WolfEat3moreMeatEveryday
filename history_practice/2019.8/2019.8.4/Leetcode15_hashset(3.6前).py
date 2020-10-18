class Solution:
    def threeSum(self,nums):
        if len(nums) < 3:
            return []
        nums.sort()
        res = set()
        # enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串)
        # 组合为一个索引序列，同时列出数据和数据下标(从0开始的)
        for i,v in enumerate(nums[:-2]):
            if i>=1 and v == nums[i-1]:
                continue
            d = {}
            for x in nums[i+1:]:
                # 我现在v和x在nums里面，我想找到-v-x,所以将-v-x
                # 丢进set，然后在下次遍历到的时候如果发现了之前
                # 要找的值，所以v,x,-v-x都存在，所以可以
                # 巧妙利用了set性质
                if x not in d:
                    d[-v-x] = 1
                else:
                    res.add((v,-v-x,x))
        return map(list,res)