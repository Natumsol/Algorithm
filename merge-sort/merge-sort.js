var fs = require("fs");
fs.readFile("src.txt", function (err, data) {
    if (err) {
        console.log("Open file src.txt Error: " + err.message);
        process.exit(-1);
    } else {
        data = data.toString("utf-8").split("\n").map(function (value) {
            return parseInt(value);
        });
        console.time("JavaScript版merge_sort:");
        merge_sort(data);
        console.timeEnd("JavaScript版merge_sort:")
    }
})

function merge_sort(data) {
    var dataTemp = new Array(data.length);
    m_sort(data, dataTemp, 0, data.length - 1);
}

function m_sort(data, dataTemp, left, right) {
    if (left < right) {
        var center = Math.floor((left + right) / 2);
        m_sort(data, dataTemp, left, center);
        m_sort(data, dataTemp, center + 1, right);
        merge(data, dataTemp, left, center + 1, right);
    }
}

function merge(data, dataTemp, leftPos, rightPos, rightEnd) {
    var leftEnd = rightPos - 1,
        tempPos = leftPos,
        total = (rightEnd - leftPos + 1);

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (data[leftPos] < data[rightPos]) {
            dataTemp[tempPos++] = data[leftPos++];
        } else {
            dataTemp[tempPos++] = data[rightPos++];
        }
    }

    while (leftPos <= leftEnd) {
        dataTemp[tempPos++] = data[leftPos++];
    }

    while (rightPos <= rightEnd) {
        dataTemp[tempPos++] = data[rightPos++];
    }

    for (var i = 0; i < total; i++ , rightEnd--) {
        data[rightEnd] = dataTemp[rightEnd];
    }
}