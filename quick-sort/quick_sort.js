var fs = require("fs");
fs.readFile("../src.txt", function (err, data) {
    if (err) {
        console.log("Open file src.txt Error: " + err.message);
        process.exit(-1);
    } else {
        data = data.toString("utf-8").split("\n").map(function (value) {
            return parseInt(value);
        });
        console.time("JavaScript版merge_sort");
        quick_sort(data, 0, data.length - 1);
        console.timeEnd("JavaScript版merge_sort")
    }
})


function swap(data, pos1, pos2){
    var temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;
}

function media3(data, left, right) {
    var center = Math.floor((left + right) / 2);
    if(data[left] > data[center]) {
        swap(data, left, center);
    }
    if(data[left] > data[right]) {
        swap(data, left, right);
    }
    if(data[center] > data[right]) {
       swap(data, center, right);
    }   
    swap(data, center, right - 1);
    return data[right - 1];
}

function quick_sort(data, left, right){
    if(left + 3 <= right) { // 如果所剩元素小于三个， 那么这不能利用快速排序了，因为Pivot的选取至少需要三个元素
        var center = Math.floor((left + right) / 2);
        var pivot = media3(data, left, right), i = left, j = right - 1;
        while(1){
            while(data[++ i] < pivot) {}
            while(data[-- j] > pivot) {}
            if(i < j) {
                swap(data, i , j);
            } else {
                break;
            }
        }
        swap(data, center, right - 1);
        quick_sort(data, left, i - 1);
        quick_sort(data, i + 1, right);
    } else {// 对于小雨3个的元素，直接利用插入排序来进行排序
        insert_sort(data, left, right);
    }
}

function insert_sort(data, left, right){
    if(left < right){
        for(var i = 1; i < right - left + 1; i ++) {
            var temp = data[i];
            for(var j = i; j > 0 && data[j - 1] > temp; j --) {
                    data[j] = data[j - 1];
            }
            data[j] = temp;
        }
    }
} 
