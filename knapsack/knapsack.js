/**
 * 背包问题分析
 * 设背包容量为C，宝石的数量为n， 第i个宝石的体积为V[i], 价值为W[i]
 */
function max(num1, num2) {
    return num1 > num2 ? num1 : num2;
}

function knapsack(C, V, W) {
    var d = new Array(V.length + 1);
    for (var i = 0; i <= V.length; i++) {
        
        d[i] = new Array(C + 1);//初始化
        
        for (var j = 0; j <= C; j++) {
            if (i) {
                d[i][j] = d[i - 1][j];
            } else {
                d[i][j] = 0;
            }
            if (i > 0 && j > V[i - 1]) {
                d[i][j] = max(d[i][j], d[i - 1][j - V[i - 1]] + W[i - 1])
            }
        }
    }
    
    var x = new Array(V.length);
    j = C;
    for(i = x.length; i > 0; i --) {
        if(d[i][j] > d[i - 1][j]){
            x[i - 1] = 1;
            j = j - V[i-1];
        } 
    }
    console.log(d[V.length][C]);
    console.log(x);

}

knapsack(10, [5, 4, 3], [20, 10, 12]);