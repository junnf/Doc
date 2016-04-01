######备份与恢复
mysqldump -u root -p dbname > backupfile.sql
mysql [options]  dbname < backupfile.sql


mysql [options] < backupfile.sql


MyISAM Static
    存取效率高
MyISAM Dynamic
    空间开销小
InnoDB
    支持事务
    数据行级锁，非数据表级锁
    MyISAM为数据表级锁
    自动识别死锁
    外键约束条件

查看auto_increment 
SELECT LAST_INSERT_ID();

ALTER TABLE AA MODIFY COLUMN SS INT;
CREATE UNIQUE INDEX A ON TABLENAME(COLUMN);


