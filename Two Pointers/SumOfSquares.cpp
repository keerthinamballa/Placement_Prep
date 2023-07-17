// 633. Sum of Square Numbers
// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

//APPROACH:

// We should try out all possible numbers whose sum of squares will be equal to c.
// One thing we can notice here through basic intuition that a, b can be in the range from 0 to sqrt(c).
// This can be solved using 2 pointer.
// Let a and b be two pointers.
// initialize a to zero and b to sqrt(c).
// We can try all possible ways until a is less than b.
// Once a becomes greater than b, we encounter the same pairs. This is not required.
// We will run a while loop, while a <= b, compute the sum of squares every time.
// If the sum of squares is less than c, we increment a.
// If it is greater than c, we decerement b.
// And if we find a pair, whose sume of squares is equal to c, return true.
// If we could not find any any pair, whose sum of squares is equal to c, return false at the end.


bool judgeSumOfSquares(int c){
    int a = 0, b = sqrt(c);
    while(a <= b){
        int possible_ans = (a*a) + (b*b);
        if(possible_ans < c) a++;
        else if(possible_ans > c) b--;
        else return true;
    }
    return false;
}

// T.C = O(SQRT(C))

