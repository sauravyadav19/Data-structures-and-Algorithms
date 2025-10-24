/*
    => Objective : We are given an array of tasks and an array of their dependencies on each other
                i.e say our tasks are [1,2,3,4]  and their dependencies among each other looks like this
                [[1,2], [3,2], [4,2], [1,3], [4,3]] here each array represents an edge and the task at the 
                first position is a prerequisite for the task at the second position,for example in
                [1,2] the first poisiton task i.e 1 is a prerequisite for task on the second posiiton
                i.e 2 and must be completed before.
    => Things to keep in mind: 
            - This is will work only on Directed Acylic graphs.
            - Why?
                - If a cycle appear that means that task is somehow indirectly dependent on itself, thus
                  creating a deadlock, Example [3,2],[2,3] here 2 is dependent on 3 and so 3 should be completed
                  before 2, but we later found out that 3 is dependent on 2 thus creating a chicken-egg situation.
                - the graph needs to directed for obivious reason of show the dependent and prerequistie 
                  relation 
            - it would be a natural instinct to show the relation ship [1,2] like this 2-->1 as to do 2 
              you need to do 1 first, but in computer science when we have a relation like this (u,v)
              and we do u --> v we mean to say that we have completed u and now are we moving to v
              so it would be more appropriate to show the arrow the other way, so in [1,2] 1 --> 2,
              which would means that 1 is completed and now we are moving to 2.
            - ANALOGY that helpled me out here was : 
                - [1,2] [3,2] [4,2] 2 is dependent on {1,2,4} so these must be completed before we can move 
                   to 2.
                   imagine 1,3,4 as small stream that will converge  to form the the river which is 2.

    => Graph would look like this: 
                ----------------------------------
                |                                |
                |                                |
                |                                v
                1 ----------> 2 <----------------3
                              ^                  ^
                              |                  |
                              |                  |
                              4-------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    return 0;
}