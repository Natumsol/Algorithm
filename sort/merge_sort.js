var fs = require("fs");
function merge(data, dataTemp, lPos, rPos, rightEnd) {
    var leftEnd = rPos - 1;
    var TmpPos = lPos;
    var total = rightEnd - lPos + 1;
    while (lPos <= leftEnd && rPos <= rightEnd) {
        if (data[lPos] < data[rPos]) {
            dataTemp[TmpPos++] = data[lPos++];
        } else {
            dataTemp[TmpPos++] = data[rPos++];

        }
    }

    while (lPos <= leftEnd) {
        dataTemp[TmpPos++] = data[lPos++];
    }

    while (rPos <= rightEnd) {
        dataTemp[TmpPos++] = data[rPos++];
    }

    for (var i = 0; i < total; i++ , rightEnd--) {
        data[rightEnd] = dataTemp[rightEnd];
    }
}
function msort(data, dataTemp, left, right) {
    if (left < right) {
        var center = Math.floor((left + right) / 2);
        msort(data, dataTemp, left, center);
        msort(data, dataTemp, center + 1, right);
        merge(data, dataTemp, left, center + 1, right);
    }
}
function merge_sort(data) {
    var dataTemp = new Array(data.length);
    msort(data, dataTemp, 0, data.length - 1);
}

function shell_sort(data) {
    var increment = Math.floor((data.length / 2));
    var temp;
    for (; increment > 0; increment =  Math.floor((increment / 2))) {
        for (var i = increment; i < data.length; i ++) {
            temp = data[i];
            for(var j = i; j >= increment; j -= increment) {
                if(temp < data[j - increment]) {
                    data[j] = data[j - increment];
                } else {
                    break;
                }
            }
            data[j] = temp;
        }
    }
}
function insert_sort(data){
    var temp;
    for(var i = 0 ; i < data.length; i ++) {
        temp = data[i];
        for(var j = i; j > 0; j --) {
            if(temp < data[j]) {
                data[j - 1] = data[j]
            }
        }
        data[j] = temp;
    }
}
var array_size = 100000;
var data = new Array(array_size);
var data2 = new Array(array_size);
var data3 = new Array(array_size);
var data4 = new Array(array_size);

for (var i = 0; i < array_size; i++) {
    data4[i] = data3[i] = data2[i] = data[i] = Math.floor(Math.random() * array_size);
}

fs.writeFile("src.txt", data.join("\n"), function (err) {
    if (err) throw err;
    else console.log("ok!");
})
console.time("merge_sort");
merge_sort(data);
console.timeEnd("merge_sort");

fs.writeFile("merge.txt", data.join("\n"), function (err) {
    if (err) throw err;
    else console.log("ok!");
})
console.time("自带排序");
data2.sort(function (prev, next) {
    return prev - next;
});
console.timeEnd("自带排序");
fs.writeFile("zidai.txt", data.join("\n"), function (err) {
    if (err) throw err;
    else console.log("ok!");
})

console.time("shell_sort");
shell_sort(data3);
console.timeEnd("shell_sort");
fs.writeFile("shell.txt", data.join("\n"), function (err) {
    if (err) throw err;
    else console.log("ok!");
})
/*
console.time("insert_sort");
insert_sort(data4);
console.timeEnd("insert_sort");
fs.writeFile("insert.txt", data.join("\n"), function (err) {
    if (err) throw err;
    else console.log("ok!");
})*/
