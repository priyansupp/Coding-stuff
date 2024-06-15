-- task1
create database assignment08;
use assignment08;
set global local_infile=1;

-- task2.1
create table ett(cid varchar(10), exam_date date, start_time time, end_time time);
load data local infile 'C:/database-07-mar-2022/exam-time-table.csv' into table ett fields terminated by ',' lines terminated by '\n' ignore  0 lines;

-- task2.2
create table cc(cid varchar(10) primary key, credits int);
load data local infile 'C:/database-07-mar-2022/course-credits.csv' into table cc fields terminated by ',' lines terminated by '\n' ignore  0 lines;

-- task2.3
create table cwsl(serial_number int, roll_number varchar(100), name varchar(100), email varchar(100), cid varchar(10));
load data local infile 'C:/database-07-mar-2022/merge.csv' into table cwsl fields terminated by ',' lines terminated by '\n' ignore  0 lines;

