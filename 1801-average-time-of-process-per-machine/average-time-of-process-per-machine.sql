# Write your MySQL query statement below
select a1.machine_id,round(avg(a1.timestamp-a2.timestamp),3) as processing_time
from  Activity a1 
inner join 
Activity a2
on a1.machine_id=a2.machine_id
and a1.process_id=a2.process_id
and a1.timestamp >a2.timestamp
group by a1.machine_id;

-- | machine_id | process_id | activity_type | timestamp | machine_id | process_id | activity_type | timestamp |
-- | ---------- | ---------- | ------------- | --------- | ---------- | ---------- | ------------- | --------- |
-- | 0          | 0          | start         | 0.712     | 0          | 0          | end           | 1.52      |
-- | 0          | 1          | start         | 3.14      | 0          | 1          | end           | 4.12      |
-- | 1          | 0          | start         | 0.55      | 1          | 0          | end           | 1.55      |
-- | 1          | 1          | start         | 0.43      | 1          | 1          | end           | 1.42      |
-- | 2          | 0          | start         | 4.1       | 2          | 0          | end           | 4.512     | 
-- | 2          | 1          | start         | 2.5       | 2          | 1          | end           | 5         |

-- | machine_id | process_id | activity_type | timestamp | machine_id | process_id | activity_type | timestamp |
-- | ---------- | ---------- | ------------- | --------- | ---------- | ---------- | ------------- | --------- |
-- | 0          | 0          | end           | 1.52      | 0          | 0          | start         | 0.712     |
-- | 0          | 1          | end           | 4.12      | 0          | 1          | start         | 3.14      |
-- | 1          | 0          | end           | 1.55      | 1          | 0          | start         | 0.55      |
-- | 1          | 1          | end           | 1.42      | 1          | 1          | start         | 0.43      |
-- | 2          | 0          | end           | 4.512     | 2          | 0          | start         | 4.1       |
-- | 2          | 1          | end           | 5         | 2          | 1          | start         | 2.5       |

-- | machine_id | process_id | activity_type | timestamp | machine_id | process_id | activity_type | timestamp |
-- | ---------- | ---------- | ------------- | --------- | ---------- | ---------- | ------------- | --------- |
-- | 0          | 0          | end           | 1.52      | 0          | 0          | start         | 0.712     |
-- | 1          | 0          | end           | 1.55      | 1          | 0          | start         | 0.55      |
-- | 2          | 0          | end           | 4.512     | 2          | 0          | start         | 4.1       |