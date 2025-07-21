class twoStacks {
    int arr[];
    int stack1, stack2;

    twoStacks() {
        arr = new int[200];
        stack1 = 100;
        stack2 = 99;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        arr[stack1++] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        arr[stack2--] = x;
    }

    // Function to remove an element from top of the stack1.

    int pop1() {
        if (stack1 == 100) {
            return -1;
        }
        return arr[--stack1];
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (stack2 == 99) {
            return -1;
        }
        return arr[++stack2];
    }
}

public class Two {
    public static void main(String[] args) {

    }
}
