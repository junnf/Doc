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



   Procs
          r:  等待运行的进程数  b:  处在非中断睡眠状态的进程数  w:  被交换出去的可运行的进程数。  此数由   linux   计算得出，但   linux
                 并不耗尽交换空间

Memory
swpd: 虚拟内存使用情况，单位：KB
free: 空闲的内存，单位KB
buff: 被用来做为缓存的内存数，单位：KB
Swap
si: 从磁盘交换到内存的交换页数量，单位：KB/秒
so: 从内存交换到磁盘的交换页数量，单位：KB/秒
IO
bi: 发送到块设备的块数，单位：块/秒
bo: 从块设备接收到的块数，单位：块/秒

System
in: 每秒的中断数，包括时钟中断
cs: 每秒的环境（上下文）切换次数

CPU
按 CPU 的总使用百分比来显示
us: CPU 使用时间
sy: CPU 系统使用时间
id: 闲置时间
