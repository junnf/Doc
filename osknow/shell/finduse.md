
#### find 文件查找

查找txt和pdf文件:

find . \( -name "*.txt" -o -name "*.pdf" \) -print

正则方式查找.txt和pdf:

find . -regex  ".*\(\.txt|\.pdf\)$"

-iregex： 忽略大小写的正则

否定参数 ,查找所有非txt文本:

find . ! -name "*.txt" -print

指定搜索深度,打印出当前目录的文件（深度为1）:

find . -maxdepth 1 -type f

定制搜索

    按类型搜索

find . -type d -print  //只列出所有目录

-type f 文件 / l 符号链接 / d 目录

find支持的文件检索类型可以区分普通文件和符号链接、目录等，但是二进制文件和文本文件无法直接通过find的类型区分出来；

file命令可以检查文件具体类型（二进制或文本）:

$file redis-cli  # 二进制文件
redis-cli: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.9, not stripped
$file redis.pid  # 文本文件
redis.pid: ASCII text

所以,可以用以下命令组合来实现查找本地目录下的所有二进制文件:

ls -lrt | awk '{print $9}'|xargs file|grep  ELF| awk '{print $1}'|tr -d ':'

    按时间搜索
            -atime 访问时间 (单位是天，分钟单位则是-amin，以下类似）
            -mtime 修改时间 （内容被修改）
            -ctime 变化时间 （元数据或权限变化）

最近第7天被访问过的所有文件:

find . -atime 7 -type f -print

最近7天内被访问过的所有文件:

find . -atime -7 -type f -print

查询7天前被访问过的所有文件:

find . -atime +7 type f -print

    按大小搜索：

w字 k M G 寻找大于2k的文件:

find . -type f -size +2k

按权限查找:

find . -type f -perm 644 -print //找具有可执行权限的所有文件

按用户查找:

find . -type f -user weber -print// 找用户weber所拥有的文件

找到后的后续动作

    删除

删除当前目录下所有的swp文件:

find . -type f -name "*.swp" -delete

另一种语法:

find . type f -name "*.swp" | xargs rm

    执行动作（强大的exec）

将当前目录下的所有权变更为weber:

find . -type f -user root -exec chown weber {} \;

注：{}是一个特殊的字符串，对于每一个匹配的文件，{}会被替换成相应的文件名；

将找到的文件全都copy到另一个目录:

find . -type f -mtime +10 -name "*.txt" -exec cp {} OLD \;

    结合多个命令

如果需要后续执行多个命令，可以将多个命令写成一个脚本。然后 -exec 调用时执行脚本即可:

-exec ./commands.sh {} \;

-print的定界符

默认使用’\n’作为文件的定界符；

-print0 使用’\0’作为文件的定界符，这样就可以搜索包含空格的文件；
