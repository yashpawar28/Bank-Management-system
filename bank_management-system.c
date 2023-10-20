// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
long long int dob, acc_num, aadhar_num;
int pin;
float balance;
char name[100];
void init(){
    dob=0;
    acc_num=1010101010101010;
    aadhar_num=0;
    balance=10000000;
    pin=9999;
    
    printf("%lld \n%lld \n%lld \n%d \n%f %s",dob,acc_num,aadhar_num,pin,balance,name);
}
int verification(){
    int pos=1,flag=0,t_pin;
    long long int t_acc_num;
    printf("Enter your Account Number:\n");
    scanf("%lld",&t_acc_num);
    if(t_acc_num==acc_num){
        flag=1;
        
    }
    if(flag==0){
        printf("Account Number does not exist in database\n");
        return -1;
    }
    flag=0;
    printf("Enter Pin Number for Verification:\n");
    scanf("%d",&t_pin);
    if(t_pin==pin){
        flag=1;
        return pos;
    }
    if(flag=0){
        printf("Incorrect pin number\n");
        return -1;
    }
}
void open_acc(){
    printf("Enter your date of birth in YYYYMMDD format\n");
    scanf("%lld",&dob);
    printf("Enter your name\n");
    scanf(" %[^\n]",name);
    printf("Enter your aadhar number\n");
    scanf("%lld",&aadhar_num);
    printf("Set your four digit pin number\n");
    scanf("%d",&pin);
    balance=0.00;
    acc_num=rand();
    printf("Congratulations, your account has been opened. Account details:\n");
    printf("Name : ");
    for(int i=0;i<strlen(name);i++)
    {
        printf("%c",name[i]);
    }
    printf("\n");
    printf("Date of birth : %lld\n",dob);
    printf("Account number : %lld\n",acc_num);
    printf("Aadhar number : %lld\n",aadhar_num);
    printf("Pin number : %d\n",pin);
    printf("Balance : %f\n",balance);
    
}
void modify(){
    int choice;
    printf("Verification...\n");
    int verify=verification();
    if(verify==-1){
        return;
    }
    else{
        printf("Verification complete :)\n");
    }
    while(1){
        
    
    printf("choose data to edit:\n");
    printf("1. Name\n");
    printf("2. Date of birth\n");
    printf("3. Pin\n");
    printf("4. Confirm and save account details\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
                printf("Enter new name\n");
                char t_name[100];
                scanf(" %[^\n]",t_name);
                strcpy(name,t_name);
                printf("Name changed to : ");
                for(int i=0;i<strlen(name);i++)
                {
                    printf("%c",name[i]);
                }
                printf("\n");
                break;
        case 2:
                printf("Enter new date of birth in YYYYMMDD format\n");
                scanf("%lld",&dob);
                printf("Date of birth changed to : %lld \n",dob);
                break;    
        case 3:
                printf("Enter new four digit pin\n");
                scanf("%d",&pin);
                printf("Pin changed to : %d \n",pin);
                break;    
        case 4:
                printf("New account details :\n");
                printf("Name : ");
                for(int i=0;i<strlen(name);i++)
                {
                    printf("%c",name[i]);
                }
                printf("\n");
                printf("Date of birth : %lld\n",dob);
                printf("Account number : %lld\n",acc_num);
                printf("Aadhar number : %lld\n",aadhar_num);
                printf("Pin number : %d\n",pin);
                printf("Balance : %f\n",balance);
                return;
        default:
                printf("Invalid choice\n");
                break;
    }
    }
    
}
void balance1(){
    printf("Verification..\n");
    int verify=verification();
    if(verify==-1){
        return;
    }
    else{
         printf("Current account balance : %0.2f\n",balance);
    }
}
void transaction()
{
    printf("verification..\n");
    int verify = verification();
    if(verify == -1)
    {
        return;
    }
    else
    {
        printf("Account verified..\n");
    }
    printf("Choose the type of transaction : \n");
    printf("1. Withdraw\n");
    printf("2. Deposit\n");
    int choice;
    scanf("%d",&choice);
    float amount;
    switch(choice)
    {
        case 1:
            printf("Enter amount to withdraw\n");
            scanf("%f",&amount);
            if(amount > balance)
            {
                printf("Not enough balance in account\n");
                break;
            }
            else
            {
                balance-=amount;
                printf("%0.2f withdrawn from account\n",amount);
                printf("Remaining account balance : %0.2f\n", balance);
            }
            break;
        case 2:
            printf("Enter amount to deposit\n");
            scanf("%f",&amount);
            balance+=amount;
            printf("%0.2f deposited to account\n",amount);
            printf("Current account balance : %0.2f\n", balance);
            break;
        default:
            printf("Invalid choice");
            return;
    }   
}
void display()
{
    printf("Enter your choice of operation\n");
    printf("1. Open new account\n");
    printf("2. Make transaction\n");
    printf("3. Check account balance\n");
    printf("4. Modify account details\n");
    printf("5. Exit\n");
    printf("Choose your operation 1 to 5\n");
}
void menu()
{
    
    while(1)
    {
        int choice;
        display();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                open_acc();
                break;
            case 2:
                transaction();
                break;
            case 3:
                balance1();
                break;
            case 4:
                modify();
                break;
            case 5:
                printf("Thank you for transacting with us");
                return;
            default:
                printf("Invalid choice");             
                break;
        }
    }
}
int main() {
    
    
    menu();
    return 0;
}