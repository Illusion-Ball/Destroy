int Solution::numSetBits(unsigned int A) {
    int count = 0;
    while (A > 0) {
        A &= (A - 1);
        count++;
    }
    return count;
}
