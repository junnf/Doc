######备份与恢复
mysqldump -u root -p dbname > backupfile.sql
mysql [options]  dbname < backupfile.sql


mysql [options] < backupfile.sql

CREATE TABLE comment(textnum int not null,commentid SMALLINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
content VARCHAR(50) not null, pushtime timestamp, 
######外键约束
constraint fk_cm FOREIGN KEY (textnum) REFERENCES text (textnum));

