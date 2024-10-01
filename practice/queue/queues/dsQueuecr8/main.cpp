/*Creating queues using templates
 */

#include <iostream>
#include <queue> //queue header file
using namespace std;

int main(){

    queue<int> myQ;

    for(int i=0; i< 10; i++)
    {
        cout << "Enqueue: " << i << endl;
        myQ.push(i);
    }

    cout << "Size of the queue: " << myQ.size() << endl;

    cout<< "End of the Queue: " <<myQ.back() <<endl;

    while(!myQ.empty())
    {
        cout<<"Dequeue: " <<myQ.front() <<endl;
        myQ.pop();
    }
}
