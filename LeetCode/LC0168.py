'''
168. Excel表列名称
给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

168. Excel Sheet Column Title
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
'''


class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        LETTER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

        column = ''
        quotient = columnNumber - 1
        while True:
            reminder = quotient % len(LETTER)
            print(reminder)
            column = LETTER[reminder] + column

            quotient = quotient // len(LETTER) - 1
            if quotient < 0:
                return column

        raise TimeoutError
