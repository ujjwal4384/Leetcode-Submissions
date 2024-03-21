class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        n = x
        rev_x=0
        
        while n>=1:
            rem = n%10
            rev_x = rev_x*10 + rem
            n=n//10
        
        return rev_x ==x