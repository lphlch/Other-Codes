'''
205. 同构字符串

给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

'''


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        def mapping(s, t):
            if len(s) != len(t):
                return False

            mapping_dict = {}
            for index, c in enumerate(s):
                mapped_c = mapping_dict.get(c, None)
                if mapped_c is None:
                    # add
                    mapping_dict[c] = t[index]
                else:
                    # check if not the same
                    if mapped_c != t[index]:
                        return False

                    continue
            return True

        # ! Isomorphic must be two-way mappings
        return mapping(s, t) and mapping(t, s)
