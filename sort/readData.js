var fs = require("fs");
var result;
function insert_sort(data) {
    var temp;
    for (var i = 0; i < data.length; i++) {
        temp = data[i];
        for (var j = i; j > 0; j--) {
            if (temp < data[j]) {
                data[j - 1] = data[j]
            }
        }
        data[j] = temp; //将第i趟的第i个元素放到前i+1个元素的合适位置
    }
}

function shell_sort(data) {
    var increment = Math.floor((data.length / 2));
    var temp;
    for (; increment > 0; increment = Math.floor((increment / 2))) {
        for (var i = increment; i < data.length; i++) {
            temp = data[i];
            for (var j = i; j >= increment; j -= increment) {
                if (temp < data[j - increment]) {
                    data[j] = data[j - increment];
                } else {
                    break;
                }
            }
            data[j] = temp;
        }
    }
}

fs.readFile("src.txt", function (err, result) {
    data = result.toString("ascii").split("\n").map(function (value) {
        return parseInt(value)
    });
    console.time("javascript版本shell_sort");
    shell_sort(data);
    console.timeEnd("javascript版本shell_sort");
})
