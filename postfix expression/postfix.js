function isNumber(num) {
    return +num == num && ("" + num).trim().length > 0;
}
function toPostFix(str) {
    var input = str.replace(/\s/g, "").match(/(\d+)|(\+|\-|\*|\/|\(|\))/g)
    var operator = {
        "+": 1,
        "-": 1,
        "*": 2,
        "/": 2
    } //定义运算符优先级
    var stackTemp = [], output = [];
    for (var i = 0; i < input.length; i++) {
        if (isNumber(input[i])) {
            output.push(input[i]);
        } else if (input[i] == ")") {
            while (stackTemp[stackTemp.length - 1] != "(") {
                output.push(stackTemp.pop());
            }
            stackTemp.pop();
        } else if (input[i] == ")") {
            stackTemp.push(input[i]);
        }
        else {
            if (!stackTemp.length) {
                stackTemp.push(input[i]);
            } else {
                if (operator[input[i]] > operator[stackTemp[stackTemp.length - 1]]) { // 当前操作符优先级 > 栈顶元素优先级
                    stackTemp.push(input[i]);
                } else {
                    while (operator[input[i]] <= operator[stackTemp[stackTemp.length - 1]]) {
                        output.push(stackTemp.pop());
                    }
                    stackTemp.push(input[i]);
                }
            }
        }
    }
    while (stackTemp.length) {
        output.push(stackTemp.pop());
    }

    return output;
}


var input = "(2 + 1) * 7 / 3 - 3";
var output = toPostFix(input);
console.log(output);