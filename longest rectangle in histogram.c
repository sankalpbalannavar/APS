/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Largest Rectangle in Histogram
*/

int largestRectangleArea(int* heights, int heightsSize){
    int* left = (int*)malloc(heightsSize*sizeof(int));
    int* right = (int*)malloc(heightsSize*sizeof(int));
    int* stack = (int*)malloc(heightsSize*sizeof(int));
    int top = -1, ans = 0;
    for(int i=0; i<heightsSize; i++) {
        while(top >= 0 && heights[stack[top]] >= heights[i]) {
            top--;
        }
        left[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = i;
    }
    top = -1;
    for(int i=heightsSize-1; i>=0; i--) {
        while(top >= 0 && heights[stack[top]] >= heights[i]) {
            top--;
        }
        right[i] = (top == -1) ? heightsSize : stack[top];
        stack[++top] = i;
    }
    for(int i=0; i<heightsSize; i++) {
        ans = fmax(ans, heights[i]*(right[i]-left[i]-1));
    }
    return ans;
}