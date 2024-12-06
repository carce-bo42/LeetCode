# https://leetcode.com/problems/buddy-strings/description/

class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:

        # If the lengths are different
        if len(s) != len(goal):
            return False

        # if they are equal but all chars are unique
        if s == goal:
            return not (len(set(s)) == len(s))

        # if some string has a character the other doesnt
        if set(s) != set(goal):
            return False

        # finally, normal comparison. Same number of elements, same set of letters.
        diffs = []
        for a, _ in enumerate(s):
            if s[a] != goal[a]:
                diffs.append(ord(s[a]) - ord(goal[a]))
                if len(diffs) == 2:
                    return s[a+1:] == goal[a+1:] if sum(diffs) == 0 else False
        return True