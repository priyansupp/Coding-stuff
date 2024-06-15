-- TASK 01 --
create database assignment04;
use assignment04;

-- TASK 02 --
create table hss_electives(roll_number int primary key, sname varchar(100) not null, cid varchar(100) not null, cname varchar(100) not null);

-- TASK 03 --
LOAD DATA LOCAL INFILE 'C:/database-31-jan-2022/HSS_ELECTIVE_ALLOCATION_2018_BATCH.csv' INTO TABLE hss_electives FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n' IGNORE 4 LINES;

-- TASK 04 --
insert into hss_electives(roll_number, sname, cid, cname) values(180101058, 'Pranav Gupta', 'HS 236', 'Sociological Perspectives on Modernity');
insert into hss_electives(roll_number, sname, cid, cname) values(null, 'Pranav Gupta', 'HS 236', 'Sociological Perspectives on Modernity');
insert into hss_electives(roll_number, sname, cid, cname) values(180101058, null, 'HS 236', 'Sociological Perspectives on Modernity');
insert into hss_electives(roll_number, sname, cid, cname) values(180101058, 'Pranav Gupta', null, 'Sociological Perspectives on Modernity');
insert into hss_electives(roll_number, sname, cid, cname) values(180101058, 'Pranav Gupta', 'HS 236', null);

-- TASK 05 --
update hss_electives set roll_number = null where roll_number =  180123047;
update hss_electives set roll_number = 180123045 where roll_number =  180123046;
update hss_electives set sname = null;
update hss_electives set cid = null where cid = 'HS 211';
update hss_electives set cname = null where cid = 'HS 245';


-- TASK 06 --
delete from hss_electives where cid = 'HS 225';
delete from hss_electives where sname LIKE '%Ajay%';

-- TASK 07 --
LOAD DATA LOCAL INFILE 'C:/database-31-jan-2022/HS225.csv' INTO TABLE hss_electives FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-31-jan-2022/ajay.csv' INTO TABLE hss_electives FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';

-- TASK 08 --
-- warning for task 07: 1 warning(s): 1062 Duplicate entry '180107005' for key 'hss_electives.PRIMARY' Records: 5  Deleted: 0  Skipped: 1  Warnings: 1
-- the warning is thrown because we tried to insert '180107005' in roll_number column which already had '18010700' and as it is primary key column(a primary key must be unique) so it can't contain duplicates.

-- TASK 09 --
alter table hss_electives drop primary key;
insert into hss_electives(roll_number, sname, cid, cname) values(180123001, 'Aditi Bihade', 'HS 225', 'Inventing the Truth: The Art and Craft of Autobiography');
alter table hss_electives add constraint mypk primary key(roll_number);
-- WARNING: Error Code: 1062. Duplicate entry '180123001' for key 'hss_electives.PRIMARY'
-- There are already duplicate entries in roll_number for '180123001' and as primary key must not contain any duplicate keys hence it throws error and can't add primary key constraint to roll_number

insert into hss_electives(roll_number, sname, cid, cname) values(180123001, 'Aditi Bihade', 'HS 225', 'Inventing the Truth: The Art and Craft of Autobiography');
-- as roll_number wasn't made primary key, so we can add duplicates also


-- TASK 10 --
LOAD DATA LOCAL INFILE 'C:/database-31-jan-2022/old-hss-electives-allotment.csv' INTO TABLE hss_electives FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 1 LINES;


-- TASK 11 --
select cid from hss_electives;

select * from hss_electives where roll_number LIKE '1701010%' or roll_number LIKE '1801010%' or roll_number LIKE '190101%' or roll_number LIKE '1701230%' or roll_number LIKE '1801230%' or roll_number LIKE '1901230%';

select * from hss_electives where roll_number LIKE '%01230%' and cname = 'Sociological Perspectives on Modernity';

select distinct cid, cname from hss_electives;

select distinct cid, cname from hss_electives order by cname desc;  -- in case of distinct
select cid, cname from hss_electives order by cname desc;           -- in case of selecting all

select sname from hss_electives where cname = 'Human Resource Management' order by sname, roll_number;
