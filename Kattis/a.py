# Libraries Included:
# Numpy, Scipy, Scikit, Pandas

# Q2: Given an integer array of tasks, where the value represents the costs, find a possible allocation within an array of servers, with capacity. E.g. Tasks: [1,3,3,2,3,4], Servers: [[10], [11]].
from bisect import bisect_left
def allocate_servers(servers, tasks):
    '''
    implement me! and print me out as well!
    '''
    tasks = sorted(tasks)[::-1]
    ans = []
    for s in servers:
        ans.append([])
        while len(tasks):
            lo = 0
            hi = len(tasks) - 1
            while (lo <= hi):
                m = (lo + hi) >> 1
                print(m)
                if s < tasks[m]:
                    hi = m - 1
                else:
                    lo = m
            if hi == -1 and len(ans[-1])==0:
                print("No such allocation")
                return -1
            ans[-1].append(tasks[lo])
            tasks = tasks[:lo] + tasks[lo+1:]
    return ans
            
        
    

servers = [10, 15] # server 1 has 10 resources available, server 2 has 15 resources available
tasks = [3,3,3,4,5,6,1] # tasks to be allocated to server.

# solution = [[3,3,3,1], [5,6,4]]

allocate_servers(servers, tasks)

# edge case (1).
# tasks = [2,2,2,2,2], n
# servers = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], m
