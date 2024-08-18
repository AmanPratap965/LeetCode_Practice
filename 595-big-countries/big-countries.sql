# Write your MySQL query statement below
    -- selecting the bigg companies
    select name,population,area from World where area>=3000000 or population>=25000000;