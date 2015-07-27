##GDB

######start
l --list
s --step 单步执行
n --next
q --quit

bt --backtrace 查看调用栈帧
i --info          i locals 查看局部变量
set var   修改变量的值 

######
break（或b） 行号 在某一行设置断点
break 函数名  在某个函数开头设置断点
break...if... 设置条件断点
continue（或c） 从当前位置开始连续而非单步执行程序
delete breakpoints  删除断点
display 变量名  跟踪查看一个变量，每次停下来都显示它的值
disable breakpoints 禁用断点
enable breakpoints  启用断点
info（或i） breakpoints 查看当前设置了哪些断点
run（或r）  从头开始连续而非单步执行程序
undisplay 取消对先前设置的那些变量的跟踪

######
watch 设置观察点
info（或i） watchpoints 查看当前设置了哪些观察点
x 从某个位置开始打印存储器的一段内容，全部当成字节来看，而不区分哪些字节属于哪些变量

######跟踪子进程
set follow-fork-mode child
