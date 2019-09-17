//for base 10 use A, base 11 use B and so on

#include <iostream>
#include <string.h>
using namespace std;

int sourcebase, targetbase;
char number[100];

int todigitvalue(char a){
    if(a>='0' && a<='9'){
        return (int)(a-'0');

    }else{
        return (int)a+10-'A';
    }

}

char fromdigitvalue(int a){
    if(a>=0 && a<=9){
        return (char)(a+'0');
    }else{
        return (char)(a-10+'A');
    }
}

void arrayriverse(char *array){
    int len=strlen(array);
    for(int i=0;i<len/2;i++){
        char temp=array[i];
        array[i]=array[len-i-1];
        array[len-i-1]=temp;
    }
}

bool validnumbercheck(int base_value, char *number){

    int len=strlen(number);
    for(int i =0;i<len;i++){
    if(todigitvalue(number[i])<base_value-1){

    }else{
        return false;

    }
    }
    return true;

}

int todecimal(int base, char *number){
    int i;
    int digitplace=1;
    int len=strlen(number);
    int result=0;
    for(i=len-1; i>=0;i--){
        result+=todigitvalue(number[i])*digitplace;
        digitplace=digitplace*base;
    }

    return result;
}

char*  fromdecimal(char result[],int base, int value){
int index=0;
    while(value>0){
            result[index++]=fromdigitvalue(value%base);
            value= value / base;
    }
    result[index] = '\0';
    arrayriverse(result);
    return result;
}

char* baseatobaseb(int base_a,  char *value, int base_b){
    char res[100];
    int dvalue=todecimal(base_a, value);
    char *result=fromdecimal(res, base_b, dvalue);
    return result;
}


int main(){

    cout<<"Enter source base of a number.."<<endl;
    cin>>sourcebase;
    cout<<"enter your number to convert base"<<endl;
    cin>>number ;
    while(validnumbercheck(sourcebase, number)==false){
        cout<<"please enter valid number"<<endl;
        cin>>number;
    }
    cout<<"enter target base of the number"<<endl;
    cin>> targetbase;
    cout<<baseatobaseb(sourcebase,number,targetbase)<<endl;
    return 0;
}
