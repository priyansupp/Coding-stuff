use cs246;
create table my_table(sid int, sname varchar(100), login char(10) unique not null, age int, spi float, primary key(sid, sname));
-- unique not null works same as primary key implicitly
-- drop table my_table;
create table table2(studid int, name varchar(100) primary key, age int, foreign key(studid, name) references my_table(sid, sname));
-- drop table table2;
alter table my_table add column location varchar(100) first;     -- all values in the rows will be set to null
alter table table2 add column gender char(10) after name;        -- column is added after name column
alter table table2 add column birth int;                         -- adds column at the end of columns
alter table my_table drop column location;
alter table table2 drop column birth;


create table R(c1 int, c2 int, c3 float, c4 double, c5 boolean);
alter table r add column c6 tinyint;    -- tinyint is same as boolean
alter table r add constraint mypk primary key (c1, c2);     -- c1,c2 becomes pk, mypk is the name of the primary key
create table s(s1 int primary key, s2 int, s3 float);
alter table r add constraint my_c2_fk foreign key(c2) references s(s1);  -- my_c2_fk is the name of the foreign key
alter table r drop primary key;             -- as no foreign key points to table r hence it'll easily be dropped. r has a foreign key which points to other table.
-- alter table s drop primary key;   -- not possible as a foreign key still points to table s
alter table r drop foreign key my_c2_fk;   -- dropping foreign key from table r
-- alter table s drop primary key;   -- can't understand why it's not working

alter table r drop column c6;    
alter table r drop column c1;  

alter table r add column c1 int default 10 first;       -- sets c1 to 10 when left blank
alter table r add column c6 int not null default 10;    -- sets c6 to 10 when left blank
alter table r change c6 c6_col char(10);    -- changes column name c6 to c6_col and datatype from into to char. be careful while changing from char to int, int to tinyint/boolean
alter table r drop column c5;

-- INSERTING VALUES IN ROWS

create table ins(c1 int, c2 int, c3 int);
insert into ins(c1,c2,c3) values (1,2,3);
insert into ins(c1,c2,c3) values (32,89,5);
alter table ins add column c4 float;       -- all unmentioned values set to null
insert into ins(c1,c3,c4) values (66,43,583.44);

alter table ins change c1 c1 int not null;   -- general schema of making change the c1 column. 
-- alter table ins change c2 c2 int not null;   -- won't execute as the c2 column already contains null values
-- insert into ins(c1,c2,c3,c4) values (null, 2, 3, 4);  -- BOTH WON'T WORK AS C1 MUST NOT BE NULL
-- insert into ins(c2,c3,c4) values (2, 3, 4); 
alter table ins change c1 c1 int default 10; 
insert into ins(c2,c3,c4) values (2, 3, 4); 

alter table ins change c2 c2 int default 200;
insert into ins(c2,c3,c4) values (null, 3, 4); 
insert into ins(c2, c3,c4) values (default, 444, 4); 
insert into ins(c1,c3,c4) values (null, 3, 4);   -- works if c1 is explicitly set to null
insert into ins() values (); 

insert into ins (c1,c2,c3,c4) values (32,null, 3, 4), (76, default,98,45);   -- multiple rows

-- UPDATING ROW
update ins set c1 = 28 where c1 = 10;  -- look for duplicate clashes if c1 is primary key
update ins set c1 = 3 where c1 >= 25;

-- DELETINS ROW
delete from ins where c1 = 1;
delete from ins where c1 >= 4;

-- SELECT

select c2 from ins;
select c3,c2 from ins;
select * from ins;   -- selects all columns
select * from ins where c2 = 200; -- all rows with c2 = 200
select c3,c1 from ins where c2 = 200 and c4 = 4;
select c4,c1,c3 from ins where c2 > 100 and c4 <> 4;   -- <> is not equal to

-- REMOVING DUPLICATES

alter table r drop column c6_col;
alter table r drop foreign key r_ibfk_1;
insert into r(c1,c2,c3,c4) values(1,2,3,4), (1,2,3,4), (4,3,22,3),(3,2,4,4),(3,2,4,4);
insert into r(c1,c2,c3,c4) values(2,2,3,4);
select distinct c2,c3,c4 from r where c1 > 1;   -- in no way all the three columns would be same in displayed table.

-- PERFORM SUM
insert into r(c1,c2,c3,c4) values(null,50,null,null);
select sum(c1) , sum(c3) from r;                -- null value amounts to 0

select min(c1), max(c2), avg(c4) from r;

-- COUNT
select count(c1) from r;    -- total 8 values in r(doesn't counts null values)
select count(c2), count(*) from r;  -- count(*) counts null values
insert into ins() values();    -- although null but not actually added to table
select count(c1), count(c2), count(c3), count(c4), count(*) from ins;
insert into ins(c1,c2,c3,c4) values(null,null,null,null);  -- explicitly setting as null hence will be added to the table
select count(c1), count(c2), count(c3), count(c4), count(*) from ins;

-- SORTING/ORDERING

select * from ins order by c1,c2;   -- sorts by c1, if clash resolves by c2
select c1,c3,c4 from ins order by c2, c4 desc;   -- sorts by c2, if clash resolves by c4 (sorting in descending order)


