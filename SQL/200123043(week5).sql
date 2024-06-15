-- task 1

create database assignment05;
use assignment05;

-- task2
create table course(cid varchar(100) primary key, cname varchar(100), l int, t int, p int, c int);
create table course_coordinator(cid varchar(100) primary key, cstart varchar(100), cend varchar(100), gsubmission varchar(100), coordinator varchar(100), exam_date varchar(100));
create table course_eligibility(cid varchar(100) not null, program varchar(100), batch_year varchar(20), batch_month varchar(20), eligibility varchar(100));
create table course_instructor(cid varchar(100), instructor varchar(100));
create table faculty(dept varchar(100), instructor varchar(100), primary key(dept, instructor));

SET GLOBAL local_infile=1;

-- task3
load data local infile 'C:/database-07-jan-2022/course.csv' into table course fields terminated by '#' lines terminated by '\n' ignore  0 lines;
load data local infile 'C:/database-07-jan-2022/course_coordinator.csv' into table course_coordinator fields terminated by '#' lines terminated by '\n' ignore  0 lines;
load data local infile 'C:/database-07-jan-2022/course_eligibility.csv' into table course_eligibility fields terminated by '#' lines terminated by '\n' ignore 0 lines;
load data local infile 'C:/database-07-jan-2022/course_instructor.csv' into table course_instructor fields terminated by '#' lines terminated by '\n' ignore 0 lines;
load data local infile 'C:/database-07-jan-2022/faculty.csv' into table faculty fields terminated by '#' lines terminated by '\n' ignore 0 lines;

-- task 4.1
select cname, count(program) from course natural join course_eligibility where course.cid = course_eligibility.cid group by cid;

-- task 4.2
create table table1 as select cid, count(distinct instructor) as cnt from course_instructor group by cid;
create table table2 as (select * from course_instructor natural join faculty natural join course);
select cid, cname, instructor from table1 natural join table2 where  cnt = (Select max(cnt) from table1) order by cid;

-- task 4.3
select distinct cname, dept from course natural join course_instructor natural join faculty where (cid like '%H ' and c <> (2 * l + 2 * t + p)/2) or (cid not like '%H ' and c <> (2 * l + 2 * t + 1 * p));

-- task 4.4
select cname, coordinator from course_coordinator natural join course as s1 where coordinator not in (select instructor from course_instructor where s1.cid =  course_instructor.cid);

-- task 4.5
select cname, gsubmission from course natural join course_coordinator order by cname;

-- task 4.6
select cname, exam_date from course natural join course_coordinator where cid not like '%H' order by cname;

-- task 4.7
select cid, cname, instructor from course natural join course_eligibility natural join course_instructor group by cid having count(program) >= 10;

-- task 4.8
select * from faculty natural join course_instructor order by instructor;

-- task 4.9
select dept, instructor from faculty where instructor not in (select instructor from course_instructor) order by dept; 