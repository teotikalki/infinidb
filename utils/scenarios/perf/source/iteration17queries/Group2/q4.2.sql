select l_shipdate, l_partkey from lineitem where l_orderkey < 1000000 order by 1, 2;
