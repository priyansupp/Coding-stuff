use cs246;
drop table t1;
create table if not exists t1(a1 int, a2 int, a3 int);
insert into t1(a1,a2,a3) values(1,2,3),(1,2,3),(1,null,null),(1,null,null);
update t1 set a1 = null where a1 = 1;
select count(*) from t1 where ((a3 = 3) or (a2 <> 2));
select count(a1), count(a2), count(a3) from t1 where ((a3 = 3) or (a2 <> 2));
select count(a1) from t1 where a2 <> 2; 
select count(a2) from t1 where a2 <> 2; 
select count(a3) from t1 where a2 <> 2; 
select count(a1) from t1 where a2 = null; 
select count(*) from t1 where a2 = null; 
-- drop table t1;
-- create table t1(c1 int,c2 int, primary key(c1,c2));
-- alter table t1 change c2 c2 int default 10;
-- create table t2(c3 int, foreign key(c3) references t1(c2));
-- insert into t1(c1,c2) values(3, 2);
-- delete from t1 where c1 = 3;
