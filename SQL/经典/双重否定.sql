-- 双重否定可以去除掉所有 不够的，不同的项  95001 语文，数学
-- 那么可以筛选掉所有 语文 ，  语文英文
-- 但是筛选不掉 语文数学英语  (也就是说这是至少的那种)
-- 所有就加count保证正好等于的的那种
select
  distinct sno
from
  sale x
where
  not exists (
    select
      *
    from
      sale y,
      supermarket
    where
      y.sno = supermarket.sno
      and sname = '教育超市'
      and not exists (
        select
          *
        from
          sale z
        where
          z.sno = x.sno
          and z.gno = y.gno
          and x.sno != y.sno
      )
  );


-- 2019年12月15日15:49:14 更
-- 更好的快速理解思路是 : 从内层开始理解
-- 比如上面的例子: 内层是 教育超市没有卖的东西 , 再套一个not exists即为 教育超市卖的任何东西 我都卖