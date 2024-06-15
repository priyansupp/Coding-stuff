use assignment08;

delimiter //
create procedure tt_violation()
begin
	create table Inter(select * from cwsl natural join ett);
	select distinct(T1.roll_number), T1.name, T1.cid, T2.cid from Inter as T1, Inter as T2 where T1.roll_number = T2.roll_number and T1.cid <> T2.cid and T1.exam_date = T2.exam_date and T1.start_time = T2.start_time group by roll_number;
end;//
delimiter ;

call tt_violation();




