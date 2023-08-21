class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        
        for length in range(1, n // 2 + 1):
            if n % length == 0:
                substring = s[:length]
                repetitions = n // length
                constructed_string = substring * repetitions
                if constructed_string == s:
                    return True
        
        return False
