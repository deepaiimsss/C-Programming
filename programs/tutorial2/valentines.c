#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int l,u;
    for(u=39;u>=-39;u--){
      for(l=-35;l<=35;l++){
if(((abs(u-25)<14&&abs(l)<6)||(abs(u-25)==13&&abs(l)<10))||(pow(abs(l)-9,2)+2*pow(u,2)<=100)||(9*abs(l)-14*u-210<=0&&u<=-3)||(pow(l,2)+2*pow(u+30,2)<=225&&pow(l,2)+2*pow(u+30,2)>=64&&u<-29)||(abs(abs(l)-11.5)<3.5&&abs(u+23)<8)){
      printf("*");}
      else{
      printf(" ");
      }
   }
   printf("\n");
 }
    return 0; 
}
