拒绝连接或者超时问题
SSH服务是否开启并且正在监听吗？

####$ ssh -tnlp

如果以上的命令没有显示SSH端口是打开的，那么说明SSH服务没有启动。查看/var/log/messages来寻找错误信息。
是否是防火墙阻止了连接？

更新你的防火墙规则来排除干扰：

#### rc.d stop iptables

或者：

#### iptables -P INPUT ACCEPT
#### iptables -P OUTPUT ACCEPT
#### iptables -F INPUT
#### iptables -F OUTPUT

你的电脑和目的主机之间是否连接？

测试你的电脑和目的主机的连接情况：

#### tcpdump -lnn -i any port ssh and tcp-syn

它会显示一些基本信息，然后等待数据交换。现在尝试你的连接。如果没有输出，就可能是你的电脑网络阻塞了。（也许是防火墙问题，也许是NAT路由的问题，祝你好运！）
Read from socket failed: Connection reset by peer

最近版本的openssh有时候会因为以上信息崩溃，据说是elliptic curve 加密的bug。在这种情况下，请编辑这个文件：

####~/.ssh/config

如果不存在，就创建它，然后加入以下内容：

HostKeyAlgorithms ssh-rsa-cert-v01@openssh.com,ssh-dss-cert-v01@openssh.com,ssh-rsa-cert-v00@openssh.com,ssh-dss-cert-v00@openssh.com,ecdsa-sha2-nistp256,ecdsa-sha2-nistp384,ecdsa-sha2-nistp521,ssh-rsa,ssh-dss

在openssh5.9中，以上的修复工作不会奏效。不过，还可以这样做：

Ciphers aes128-ctr,aes192-ctr,aes256-ctr,aes128-cbc,3des-cbc 
MACs hmac-md5,hmac-sha1,hmac-ripemd160

可以访问discussion来查看openssh的bug问题. 
