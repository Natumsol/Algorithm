var fs = require("fs");
process.stdin.setEncoding('utf8');
var events = require("events");
var emitter = new events.EventEmitter(); //事件发射器
var num;
console.log("请输入生成随机数的个数：\n")
process.stdin.on('readable', function () {
    var chunk = process.stdin.read();
    if (chunk !== null) {
        if (Number.isInteger(parseInt(chunk))) {
            num = parseInt(chunk);
            emitter.emit("init");
        } else {
            console.log("输入不合法，请重新输入！\n");
        }

    }
});
emitter.addListener("init", function () {
    generate(num);
})

function generate(num) {
    var data = new Array(num);
    for(var i = 0 ;  i< data.length; i ++) {
        data[i] = Math.floor(Math.random() * num);
    }
    fs.writeFile("src.txt", data.join("\n"), function(err){
        if(err) throw err;
        else {
            console.log("save ok!");
            process.exit(0);
        }
    })
}