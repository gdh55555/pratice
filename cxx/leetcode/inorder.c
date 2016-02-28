#include <stdio.h>

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};


void  inorderTraversal(struct TreeNode* root, int* returnSize) {
    int i = 0;
    //returnSize = (int *)malloc(1000 *sizeof(int));
    //memset(returnSize, 1000, 0);
    struct TreeNode* cur = root;
    struct TreeNode* pre = NULL;
    while(cur != NULL){
        if(cur->left == NULL){
            returnSize[i++] = cur->val;
            printf("%d\n", returnSize[i-1]);
            cur = cur->right;
        }else{
            pre = cur->left;
            while(pre->right !=NULL && pre->right != cur)
                pre = pre->right;
            if(pre->right == NULL){
                pre->right = cur;
                cur = cur->left;
            }
            else{
                pre->right = NULL;
                returnSize[i++] = cur->val;
                printf("%d\n", returnSize[i-1]);
                cur = cur->right;
            }
        }
    }

}

int main(){
    int a[10];
    struct TreeNode root;
    printf("1-----\n");
    root.val = 1;
    root.left = NULL;
    root.right = NULL;
    printf("-----\n");
    //int* p =inorderTraversal(&root, a);
    int i;
    inorderTraversal(&root, a);
    //printf("in main p %d\n", *p);
    for(i = 0; i< 10; ++i)
        printf("%d ", a[0]);
    printf("\n");
}
