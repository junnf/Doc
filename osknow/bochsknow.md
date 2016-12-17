###
dd if=c08.bin of=hard.img seek=100 count=2 bs=512 conv=notrunc
#####count 扇区数量
#####conv 连续性
#####seek 从某扇区读写



