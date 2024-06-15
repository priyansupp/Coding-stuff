CREATE DATABASE CS246;
USE cs246;
CREATE TABLE course ( 
	`CourseNo.` VARCHAR(100) PRIMARY KEY, 
	`Course Title` VARCHAR(100) NOT NULL, 
	L INT NOT NULL, 
	T INT NOT NULL, 
	P INT NOT NULL, 
	C INT NOT NULL, 
	`Type of Course` VARCHAR(100) NOT NULL);
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/courses.csv' INTO TABLE course FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n' IGNORE 1 LINES;



use cs246;
create table course_offered_to ( `CourseNo.` varchar(100), `Type of Course` varchar(100) not null, `Offered to` varchar(100) not null, primary key(`CourseNo.`), foreign key(`CourseNo.`) references course(`CourseNo.`) on delete cascade on update cascade);
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/courses-offered-to.csv' INTO TABLE course_offered_to FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n' IGNORE 1 LINES;



use cs246;
create table course_exam_slot ( `CourseNo.` varchar(100), `Exam Slot` varchar(100), `Exam Date and Time` varchar(100), primary key(`CourseNo.`), foreign key(`CourseNo.`) references course(`CourseNo.`) on delete cascade on update cascade);
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/courses-exam-slots.csv' INTO TABLE course_exam_slot FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n' IGNORE 1 LINES;


use cs246;
create table faculty ( `faculty id` int, `department name` varchar(100) not null, `faculty name` varchar(100) not null, primary key(`faculty id`));
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ce.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ch.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/cl.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/cs.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/da.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/dd.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/dm.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ee.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/en.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/hs.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ifst.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ls.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ma.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/me.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/nt.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ph.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/ra.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty/rt.csv' INTO TABLE faculty FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';


use cs246;
create table faculty_course_allotment ( `CourseNo` varchar(100), `department name` varchar(100) not null, `faculty id` int, primary key(`CourseNo`, `faculty id`), foreign key(`CourseNo`) references course(`CourseNo.`) on delete cascade on update cascade, foreign key(`faculty id`) references faculty(`faculty id`));
LOAD DATA LOCAL INFILE 'C:/database-24-jan-2022/faculty-course-allotment.csv' INTO TABLE faculty_course_allotment FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';


 













 