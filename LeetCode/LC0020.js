/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    const left_vaild = ['(', '{', '['];
    const right_vaild = [')', '}', ']'];

    let stack = [];

    for (let index = 0; index < s.length; index++) {
        const element = s[index];
        // console.log(element);
        // console.log(stack);
        if (left_vaild.includes(element)) {
            stack.push(element);
            // console.log('push: ' + element);
        }
        else if (right_vaild.includes(element)) {
            if (stack.length == 0) {
                return false;
            }
            let left = stack.pop();
            // console.log('left: ' + left);
            if (left_vaild.indexOf(left) != right_vaild.indexOf(element)) {
                return false;
            }
        }
    }

    if (stack.length != 0) {
        return false;
    }
    return true;

};