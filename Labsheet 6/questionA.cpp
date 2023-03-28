#include <iostream>
using namespace std;

class MinStack {
public:
    int elements[1000000]; // maximum size of stack
    int size;
    int min_element;
    int min_elements_stack[1000000]; // maximum size of stack
    int min_elements_top;

    MinStack() {
        size = 0;
        min_element = INT_MAX; // initialize with maximum integer value
        min_elements_top = 0;
    }

    void push(int val) {
        if (size < 1000000) { // check if stack is full
            elements[size] = val;
            size++;

            if (val < min_element) { // update minimum element variable
                min_element = val;
            }

            min_elements_stack[min_elements_top] = min_element; // push minimum element onto min_elements_stack
            min_elements_top++;
        }
    }

    void pop() {
        if (size > 0) { // check if stack is not empty
            size--;

            min_elements_top--; // pop corresponding minimum element from min_elements_stack

            if (min_elements_top > 0) { // set min_element to the top of the min_elements_stack
                min_element = min_elements_stack[min_elements_top - 1];
            } else { // if min_elements_stack is empty, set min_element to INT_MAX
                min_element = INT_MAX;
            }
        }
    }

    int top() {
        if (size > 0) {
            return elements[size - 1];
        }
        return -1;
    }

    int getMin() {
        if (min_elements_top > 0) {
            return min_elements_stack[min_elements_top - 1];
        }
        return INT_MAX;
    }
};


int main() {
    int n, m;
    cin >> n;

    MinStack ms;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.push(x);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            ms.push(x);
        } else if (op == 2) {
            ms.pop();
        } else if (op == 3) {
            cout << ms.top() << endl;
        } else if (op == 4) {
            cout << ms.getMin() << endl;
        }
    }

    return 0;
}
