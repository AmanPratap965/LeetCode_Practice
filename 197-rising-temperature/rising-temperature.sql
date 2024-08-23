# Write your MySQL query statement below
select id from weather w1 where temperature>(select temperature from weather w2 where w1.recordDate=DATE_ADD(w2.recordDate,interval 1 day));