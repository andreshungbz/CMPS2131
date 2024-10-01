
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
    std::priority_queue<int>q;
            for(int value: {1,5,6,7,2,3,4,9,0}){q.push(value);}
               print_queue(q);
}
