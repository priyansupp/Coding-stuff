-- task1
create database assignment06;
use assignment06;

-- task2
create table course(cid varchar(100) primary key, cname varchar(100), l int, t int, p int, c int);
create table course_coordinator(cid varchar(100) primary key, cstart varchar(100), cend varchar(100), gsubmission varchar(100), coordinator varchar(100), exam_date varchar(100));
create table course_eligibility(cid varchar(100) not null, program varchar(100), batch_year varchar(20), batch_month varchar(20), eligibility varchar(100));
create table course_instructor(cid varchar(100), instructor varchar(100));
create table faculty(dept varchar(100), instructor varchar(100), primary key(dept, instructor));
SET GLOBAL local_infile=1;

-- task3
load data local infile 'C:/database-14-feb-2022/course.csv' into table course fields terminated by '#' lines terminated by '\n' ignore  0 lines;
load data local infile 'C:/database-14-feb-2022/course_coordinator.csv' into table course_coordinator fields terminated by '#' lines terminated by '\n' ignore  0 lines;
load data local infile 'C:/database-14-feb-2022/course_eligibility.csv' into table course_eligibility fields terminated by '#' lines terminated by '\n' ignore 0 lines;
load data local infile 'C:/database-14-feb-2022/course_instructor.csv' into table course_instructor fields terminated by '#' lines terminated by '\n' ignore 0 lines;
load data local infile 'C:/database-14-feb-2022/faculty.csv' into table faculty fields terminated by '#' lines terminated by '\n' ignore 0 lines;


-- task4.1
-- NESTED:
select cname, programcount from course left outer join (select cid, count(program) as programcount from course_eligibility group by cid) as c1 on course.cid = c1.cid; 

-- CORRELATED NESTED:
select cname, programcount from course as c1 left outer join (select cid, count(program) as programcount from course_eligibility group by cid) as c2 on c1.cid = c2.cid where exists (select cid from course where cid = c1.cid); 

-- task4.2
-- NESTED:
create table table1 as select cid, count(distinct instructor) as cnt from course_instructor group by cid;
select cid, cname, instructor from table1 natural join course_instructor natural join faculty natural join course as finaltable1 where finaltable1.cid in (select c1.cid from course as c1) and cnt = (Select max(cnt) from table1);

-- CORRELATED NESTED:
create table table2 as select cid, count(distinct instructor) as cnt from course_instructor group by cid;
select cid, cname, instructor from table2 natural join course_instructor natural join faculty natural join course as finaltable2 where exists (select * from course as c1 where finaltable2.cid = c1.cid) and cnt = (Select max(cnt) from table1);


-- task4.3
-- NESTED:
select distinct C1.cname, faculty.dept from course as C1 join course_instructor as C2 on C1.cid = C2.cid join faculty on faculty.instructor=C2.instructor where cname in (select cname from course where((c <> ((2*l)+(2*t)+p)/2) and cid like '%H' or (c <> ((2*l)+(2*t)+p) and cid not like '%H')));

-- CORRELATED NESTED:
select distinct C1.cname, faculty.dept from course as C1 join course_instructor as C2 on C1.cid = C2.cid join faculty on faculty.instructor=C2.instructor where exists (select cname from course where((c <> ((2*l)+(2*t)+p)/2) and cid like '%H' or (c <> ((2*l)+(2*t)+p) and cid not like '%H')) and course.cname = C1.cname);


-- task4.4
-- NESTED:
select cname, coordinator from course_coordinator natural join course as s1 where s1.cid in (select c1.cid from course as c1) and coordinator not in (select instructor from course_instructor where s1.cid =  course_instructor.cid);
-- CORRELATED NESTED:
select cname, coordinator from course_coordinator natural join course as s1 where exists (select * from course as c1 where s1.cid = c1.cid) and coordinator not in (select instructor from course_instructor where s1.cid =  course_instructor.cid);


-- task4.5
-- NESTED:
select cname, gsubmission from course natural join course_coordinator as c1 where c1.cid in (select c2.cid from course as c2);

-- CORRELATED NESTED:
select cname, gsubmission from course natural join course_coordinator as c1 where exists (select * from course as c2 where c1.cid = c2.cid);

-- task4.6
-- NESTED:
select cname, exam_date from course natural join course_coordinator as c1 where c1.cid in (select c2.cid from course as c2) and cid not like '%H';

-- CORRELATED NESTED:
select cname, exam_date from course natural join course_coordinator as c1 where exists (select * from course as c2 where c1.cid = c2.cid) and cid not like '%H';

-- task 4.7
-- NESTED:
select cid, cname, instructor from course natural join course_instructor as c1 where c1.cid = course.cid and c1.cid in (select cid from (select cid, count(program) as programcount from course_eligibility group by cid) as c2 where c2.programcount >= 10);

-- CORRELATED NESTED:
select cid, cname, instructor from course natural join course_instructor as c1 where c1.cid = course.cid and exists (select * from (select cid, count(program) as programcount from course_eligibility group by cid) as c2 where c2.programcount >= 10 and c1.cid = c2.cid);

-- task 4.8
-- NESTED:
select * from faculty natural join course_instructor as c1 where c1.instructor in (select instructor from faculty);

-- CORRELATED NESTED:
select * from faculty natural join course_instructor as c1 where exists (select * from faculty as c2 where c1.instructor = c2.instructor);

-- task 4.9
-- NESTED:
select dept, instructor from faculty where instructor not in (select instructor from course_instructor); 

-- CORRELATED NESTED:
select dept, instructor from faculty where not exists (select * from course_instructor as c where faculty.instructor = c.instructor); 


-- task5

create view view4_1 as select cname, programcount from course left outer join (select cid, count(program) as programcount from course_eligibility group by cid) as c1 on course.cid = c1.cid; 

create view view4_2 as select cid, cname, instructor from table1 natural join course_instructor natural join faculty natural join course as finaltable1 where finaltable1.cid in (select c1.cid from course as c1) and cnt = (Select max(cnt) from table1);

create view view4_3 as select distinct C1.cname, faculty.dept from course as C1 join course_instructor as C2 on C1.cid = C2.cid join faculty on faculty.instructor=C2.instructor where cname in (select cname from course where((c <> ((2*l)+(2*t)+p)/2) and cid like '%H' or (c <> ((2*l)+(2*t)+p) and cid not like '%H')));

create view view4_4 as select cname, coordinator from course_coordinator natural join course as s1 where s1.cid in (select c1.cid from course as c1) and coordinator not in (select instructor from course_instructor where s1.cid =  course_instructor.cid);

create view view4_5 as select cname, gsubmission from course natural join course_coordinator as c1 where c1.cid in (select c2.cid from course as c2);

create view view4_6 as select cname, exam_date from course natural join course_coordinator as c1 where c1.cid in (select c2.cid from course as c2) and cid not like '%H';

create view view4_7 as select cid, cname, instructor from course natural join course_instructor as c1 where c1.cid = course.cid and c1.cid in (select cid from (select cid, count(program) as programcount from course_eligibility group by cid) as c2 where c2.programcount >= 10);

create view view4_8 as select * from faculty natural join course_instructor as c1 where c1.instructor in (select instructor from faculty);

create view view4_9 as select dept, instructor from faculty where instructor not in (select instructor from course_instructor); 


