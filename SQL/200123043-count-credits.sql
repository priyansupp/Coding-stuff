use assignment08;


delimiter //
create procedure count_credits()
begin
create table temp as (select * from cwsl natural join cc);
select * from (select roll_number, stud_name, sum(credits) as s from temp group by stud_name) as tp where tp.s > 40 group by tp.roll_number;
end; //
delimiter ;

call count_credits();


