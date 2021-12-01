./paging-policy.py -s 0 -n 10 -p FIFO -c >> result.txt
./paging-policy.py -s 1 -n 10 -p FIFO -c >> result.txt
./paging-policy.py -s 2 -n 10 -p FIFO -c >> result.txt

./paging-policy.py -s 0 -n 10 -p LRU -c >> result.txt
./paging-policy.py -s 1 -n 10 -p LRU -c >> result.txt
./paging-policy.py -s 2 -n 10 -p LRU -c >> result.txt

./paging-policy.py -s 0 -n 10 -p OPT -c >> result.txt
./paging-policy.py -s 1 -n 10 -p OPT -c >> result.txt
./paging-policy.py -s 2 -n 10 -p OPT -c >> result.txt