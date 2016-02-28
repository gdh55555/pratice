import java.util.*;
class Solution{
    public static void main(String[] args){
        int test[] = {3,4,6,2};
        System.out.println(Arrays.toString(test));
        System.out.println(Arrays.toString(get_max_sub_array(test, 2)));
    }
    public static int[] get_max_sub_array(int[] nums, int k) {
        int[] res = new int[k];
        int len = 0;
        for (int i = 0; i < nums.length; i++) {
            while (len > 0 && len + nums.length - i > k && res[len - 1] < nums[i]) {
                len--;
            }
            if (len < k)
                res[len++] = nums[i];
        }
        return res;
    }
}  
