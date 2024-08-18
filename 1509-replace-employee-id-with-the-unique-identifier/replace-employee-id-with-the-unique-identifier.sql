# Write your MySQL query statement below
select empUNI.unique_id , Emp.name from Employees as Emp left join EmployeeUNI as empUNI on Emp.id=empUNI.id; 