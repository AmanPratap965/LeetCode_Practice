# Write your MySQL query statement below

with cte as (
    select query_name,
    rating/position as ratio, 
    case when rating<3 then 1 
    else 0 end as quality_binary
    from Queries
)

select query_name, round(avg(ratio),2) as quality, round((sum(quality_binary)/count(*))*100,2) as poor_query_percentage
from cte
group by query_name 
having query_name is not null;