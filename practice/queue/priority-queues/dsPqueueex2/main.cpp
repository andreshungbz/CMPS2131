
/*priority queue example.*/


#include <functional>
#include <queue>
#include <vector>
#include <iostream>

template <typename T> void print_queue(T& q)
{
    while (!q.empty()){
        std::cout<<q.top()<<" ";
        q.pop();
    }

}

int main(){
    std::priority_queue<int, std::vector<int>, std::greater<int> >q2;
    for(int value:{1,4,7,9,2,4,0,9}){q2.push(value);}
    print_queue(q2);
}
