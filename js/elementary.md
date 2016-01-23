for (var x of iterable_var) {

}//本身元素

for (vat x in iterable_var) {

}//对象属性元素
a = [1,2,3]
a.name = 1
//得到结果1,2,3,'name'
var a = ['A', 'B', 'C'];
a.forEach(function (element, index, array) {
// element: 指向当前元素的值
// index: 指向当前索引
// array: 指向Array对象本身
alert(element);
});

Set Array Map

######函数
var abs = function (x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
};

function abs(x) {
    if (x >= 0) {
            return x;
    } else {
        return -x;
    }
}

'use strict';

function foo() {
    var sum = 0;
for (let i=0; i<100; i++) {
sum += i;
}
i += 1; // SyntaxError
}
)}
