# Write your MySQL query statement below
select id from weather w1 where temperature>(select temperature from weather w2 where w2.recordDate=DATE_SUB(w1.recordDate,interval 1 day));