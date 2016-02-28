class HammingWeight{
     static   int m1 = 0x55555555;
     static   int m2 = 0x33333333;
     static   int m3 = 0x0f0f0f0f;
     static   int m4 = 0x00ff00ff;
     static   int m5 = 0x0000ffff;
     static   int h01 = 0x01010101;

    public static int hammingWeight(int n) {
        n -= n >> 1 & m1;
        n = (n + n >> 2) & m2;
        n = (n + n >> 4) & m3;
        n += n >> 8;
        n += n >> 16;
        return n & 0xf;
    }
    //This uses fewer arithmetic operations than any other known  
    ////implementation on machines with slow multiplication.
    ////It uses 17 arithmetic operations.
   public static int popcount_2(int x) {
        x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
        x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
        x = (x + (x >> 4)) & m3;        //put count of each 8 bits into those 8 bits 
        x += x >>  8;  //put count of each 16 bits into their lowest 8 bits
        x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
        x += x >> 32;  //put count of each 64 bits into their lowest 8 bits
        return x & 0x7f;
    }

    public static void main(String[] args){
        System.out.println(hammingWeight(1));
        System.out.println(popcount_2(1));
    }
}
