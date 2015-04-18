/*
Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
    
    stack<int> dataStack;
    stack<int> minStack;
    
public:
    void push(int x) {
        if(dataStack.empty()){
            dataStack.push(x);
            minStack.push(x);
        }
        else{
            if(minStack.top()>=x){
                minStack.push(x);
            }
            dataStack.push(x);
        }
    }

    void pop() {
        if(dataStack.top()==minStack.top()){
            dataStack.pop();
            minStack.pop();
        }else{
            dataStack.pop();
        }
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();   
    }
};