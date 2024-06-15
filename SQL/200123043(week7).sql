-- task1
create database assignment07;
use assignment07;
set global local_infile=1;

-- task2.1
delimiter //
create function f1(roll int) returns int deterministic
begin
    declare joined_year int;
    set joined_year = 2000 + (roll / 1e7);
    return joined_year;
end;//
delimiter ;

-- task2.2
delimiter //
create function f2(roll int) returns varchar(100) deterministic
begin
	declare programcode int;
    declare ans varchar(10);
    set programcode = (roll / 1e5) % 100;
    if(programcode = 1)
    then
		set ans = 'B. Tech';
	else
		set ans = 'B. Des';
	end if;
    return ans;
end;//
delimiter ;

-- task2.3
delimiter //
create function f3(roll int) returns varchar(10) deterministic
begin
	declare deptcode int;
    declare ans varchar(10);
    set deptcode = (roll / 1e3) % 100;
    case 
    when (deptcode = 1)
    then
		set ans = 'CSE';
	when (deptcode = 2)
    then
		set ans = 'ECE';
	when(deptcode = 3)
    then
		set ans = 'ME';
	when(deptcode = 4)
    then
		set ans = 'CE';
	when(deptcode = 5)
    then
		set ans = 'DD';
	when(deptcode = 6)
    then
		set ans = 'BSBE';
	when(deptcode = 7)
    then
		set ans = 'CL';
	when(deptcode = 8)
    then
		set ans = 'EEE';
	when(deptcode = 21)
    then
		set ans = 'EPH';
	when(deptcode = 22)
    then
		set ans = 'CST';
	when(deptcode = '23')
    then
		set ans = 'M & C';
	end case;
    return ans;
end;//
delimiter ;

-- task3
create table hss_electives(roll_number int primary key, sname varchar(100) not null, cid varchar(100) not null, cname varchar(100) not null);

-- task4
create table student_details(roll_number int primary key, sname varchar(100) not null, joined_year int not null, joined_program varchar(100) not null, joined_dept varchar(100) not null);

-- task5
delimiter |
create trigger trig1 before insert on hss_electives
	for each row 
	begin
		insert into student_details set roll_number = new.roll_number, sname = new.sname, joined_year = f1(new.roll_number), joined_program = f2(new.roll_number), joined_dept = f3(new.roll_number);
	end;
|
delimiter ;

-- task6
load data local infile 'C:/HSS_ELECTIVE_ALLOCATION_2018_BATCH.csv' into table hss_electives fields terminated by '#' lines terminated by '\n' ignore  4 lines;


-- task7.1
insert into hss_electives(roll_number, sname, cid, cname) values(AB0204028, 'Priyanshu', 'CS246', 'DBMS');
insert into hss_electives(roll_number, sname, cid, cname) values(AB0105093, 'Gaurav', 'CS246', 'DBMS');

-- task7.4
insert into hss_electives(roll_number, sname, cid, cname) values('180101001', 'Priyanshu', 'HS 113', 'Cognitive Psychology');
insert into hss_electives(roll_number, sname, cid, cname) values('180101002', 'Anuj', 'HS 246', 'Archaeology');


-- task8
delimiter |
create trigger trig2 before update on hss_electives
	for each row 
	begin
		update student_details set roll_number = hss_electives.roll_number, sname = hss_electives.sname, joined_year = f1(hss_electives.roll_number), joined_program = f2(hss_electives.roll_number), joined_dept = f3(hss_electives.roll_number);
	end;
|
delimiter ;



-- task 9
delimiter |
create trigger trig3 after delete on hss_electives
	for each row 
	begin
		delete from student_details where roll_number = old.roll_number;
	end;
|
delimiter ;

