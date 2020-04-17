#include <stdio.h>

const int MAX_INT_LENGTH = 101; // string length for representing 100 digits

///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////


//
// AddTwoBigNumbers: to sum up two big numbers represented as digits in a char clear_char_array
//
// input:  char bigN[], char bigM[]:  two large numbers
// output the sum as a big number in the input array char sum[]
void AddTwoBigNumbers(char bigN[], char bigM[], char sum[])
{
    int num1[101],num2[101],sumofnum[101];
    int x,y;
    for (x=0;bigN[x]!='\0';x++){
        num1[x]=bigN[x]-'0';
    }
    for (y=0;bigM[y]!='\0';y++){
        num2[y]=bigM[y]-'0';
    }
    int carry=0;
    int k=0,i=x-1,j=y-1;
    for(;i>=0 && j>=0;i--,j--,k++){
        sumofnum[k] = (num1[i]+num2[j]+carry)%10;
        carry=(num1[i]+num2[j]+carry)/10;
    }
    if (x>y){
        while (i>=0){
            sumofnum[k++] = (num1[i]+carry)%10;
            carry=(num1[i--]+carry)/10;
        }
    }
    else if (y>x) {
        while (j>=0){
            sumofnum[k++] = (num2[j]+carry)%10;
            carry=(num2[j--]+carry)/10;
        }
    }
    else{
        if (carry>0){
            sumofnum[k++]=carry;
        }
    }
    sum=sumofnum;
}


///////// DO NOT MODIFY ANYTHING BELOW THIS LINE /////////

// Function: main function
// ==============================================================
int main()
{
  char bignum[2][MAX_INT_LENGTH]; // bignum[0] and bignum[1] are to store the digits of the two input number
  char sum[MAX_INT_LENGTH+1];     // to store the sum of the two big numbers

  // read in two numbers
  scanf("%s", bignum[0]);
  scanf("%s", bignum[1]);

  // calculate sum of the two numbers
  AddTwoBigNumbers(bignum[0], bignum[1], sum);

  // display the sum on screen
  printf("%s\n", sum);


  return 0;
}
