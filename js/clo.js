function sum(arr) {
    return arr.reduce(function (x, y) {
            return x + y;
        });
}
print(sum([1,2,3]))

function count() {
    var arr = [];
    for (var i=1; i<=3; i++) {
            arr.push(function () {
                        print(i)
                        return i * i;
                    });
        }
    return arr;
}

var results = count();
var f1 = results[0];
var f2 = results[1];
var f3 = results[2];
print(f1());
function add(n, m) {
    return function (f) {
            return function (x) {
                        return m(f)(n(f)(x));
                    }
        }
}
print(add(1,2));
function create_counter(initial) {
    var x = initial || 0;
    return {
            inc: function () {
                        x += 1;
                        return x;
                    }
        }
}
var c1 = create_counter();
print(c1.inc()); // 1
print(c1.inc()); // 1
print(c1.inc()); // 1

print(create_counter().inc());
print(create_counter().inc());
print(create_counter().inc());

