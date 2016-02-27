##shellLearn
![](https://github.com/junnf/Doc/raw/master/osknow/shell/image/signalname.png)

##array

![](https://github.com/junnf/Doc/raw/master/osknow/shell/image/array.png)

##find + xargs

##查找并删除
find . -type f -name '*.txt' -print0 | xargs -0 rm -f

简单统计文件行数
find . -type f -name '*.py' -print0 | xargs -0 wc -l

##tr 
tr -d 
echo "aa bb" | tr -d 'a'

tr -c
echo a 1 b 2 c 3 | tr -d -c '0-9 \n'
==>  1 2 3

![](https://github.com/junnf/Doc/raw/master/osknow/shell/image/tr_type.png)

eg. tr '[:lower:]' '[:upper:]'

##grep
grep "*" * -lR | xargs file


##sort
-n 按数字进行排序 VS -d 按字典序进行排序
-r 逆序排序
-k N 指定按第N列排序


