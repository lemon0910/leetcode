class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        l = []
        d = {}
        for i in range(len(num)):
            d[num[i]] = i

        for i in range(len(num)):
            gap = target - num[i]
            if d.has_key(gap) and i != d[gap]:
                l.append(i + 1)
                l.append(d[gap] + 1)
                break

        return l