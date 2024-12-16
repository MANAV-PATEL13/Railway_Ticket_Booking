#include<stdio.h>
#include<string.h>
char name[50], password[10], contact[15];//global variables
char train_no[10],train_name[25],time[10],price[10],date[10];
void welcome(){
    for(int i=0;i<15;i++){
        printf(":");
    }
    printf("\033[33mWelcome to the Railways Booking System\033[0m");
    for(int i=0;i<15;i++){
        printf(":");
    }
}
void end(){
    for(int i=0;i<68;i++){
        printf(":");
    }
}
int main()
{
    system("cls");//clean screen
    while(1){
        
        welcome();
        printf("\n\n");
    printf("        1.Login\n        2.Create Account\n\033[31m        0.Exit\033[0m\n");
    printf("\n");
    end();
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            login();
            break;
        case 2:
            create_account();
            break;        
        case 0:

            return 0;
        default:
            printf("\033[36mInvalid choice\033[0m\n");
            break;
    }
    }
}
void create_account(){    
    system("cls");
    printf("\033[36mCreating account\033[0m\n");
    printf("Enter your name: ");
    scanf("%s",name);
    printf("\nEnter your password(up to 10 characters): ");
    scanf("%s",password);
    FILE *fp = fopen("accounts.txt", "r");//fp is a pointer for file
    if(fp != NULL) {               
            //view saved the name and password in use and pasw          
            char use[50], pasw[10];
            while(fscanf(fp, "%s %s", use, pasw) == 2/*2 is number of how many details is read*/) {
                if(strcmp(use, name) == 0) {
                    system("cls");
                    printf("\033[31mAccount already exists with this name! Try other Name or Password\033[0m\n");
                    fclose(fp);
                    return;
                }
            }
        fclose(fp);
    }
    printf("\nEnter contact number: ");
    scanf("%s", contact);    
    // Open file in append mode to add new account details for history
    fp = fopen("accounts.txt", "a");
    if(fp != NULL) {
        fprintf(fp, "%s %s %s\n", name, password, contact);
        fclose(fp);
        system("cls");
        printf("\n\033[32mAccount created successfully\033[0m\n");
    } else {
        printf("\n\033[31mError creating account!\033[0m\n");
    }
}
void login(){
    int attem = 0;
    while(attem < 3) {//allow maximum 3 attempts
        system("cls");
        printf("\033[34mLogin\033[0m\n");
        printf("Enter your name: ");
        scanf("%s",name);
        printf("\nEnter your password: ");
        scanf("%s",password);
        FILE *fp = fopen("accounts.txt", "r");
        if(fp != NULL) {
            char use[50], pasw[10], cont[15];  // Added cont to match file format
            while(fscanf(fp, "%s %s %s", use, pasw, cont) == 3) {  // Changed to read 3 fields
                if(strcmp(use, name) == 0 && strcmp(pasw, password) == 0) {
                    system("cls");
                    printf("\n\033[32mLogin successful\033[0m\n");
                    dashboard();
                    fclose(fp);
                    return;
                }
            }
            attem++;
            if(attem < 3) {
                printf("\n\033[31mInvalid name or password. %d attempts remaining\033[0m\n", 3-attem);
            } else {
                printf("\n\033[31mToo many failed attempts. Please try again later.\033[0m\n");
            }
            fclose(fp);
        }
    }
    return;
}
void dashboard(){
    int choice;
    system("cls");
    printf("::::::::\033[36mMain Menu\033[0m::::::::\n");
    printf("1.Book Ticket\n2.Cancel Ticket\n3.View Ticket\n\033[31m0.Exit\033[0m\n");
    printf("Enter your choice: ");
    
    scanf("%d",&choice);
    switch(choice){
        case 1:
            book_ticket();
            break;
        case 2:
            cancel_ticket();
            break;
        case 3:
            view_ticket();
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("\033[31mInvalid choice\033[0m\n");
            break;
    }
}
void book_ticket(){
    system("cls");
    printf("\033[34mBooking Ticket\033[0m\n");
    printf("%-10s%-25s%-10s%-10s\n","Train No.","Train name","Time","Price");
    printf("--------------------------------------------------\n");
     printf("%-10s%-25s%-10s%-10s\n","20959","BL Vadnagar sup","06:30 AM","100");
    printf("%-10s%-25s%-10s%-10s\n","12345","Rajdhani Express","10:00 AM","350");
    printf("%-10s%-25s%-10s%-10s\n","12346","Shatabdi Express","11:00 AM","755");
    printf("%-10s%-25s%-10s%-10s\n","12461","Vande Bharat Express","12:00 PM","1200");
    printf("--------------------------------------------------\n");    
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==0){
        dashboard();        
    }
    switch(choice){
        case 1:
            strcpy(train_no,"20959");
            strcpy(train_name,"BL Vadnagar sup");
            strcpy(time,"06:30 AM");
            strcpy(price,"100");
            break;
        case 2:
            strcpy(train_no,"12345");
            strcpy(train_name,"Rajdhani Express");
            strcpy(time,"10:00 AM");
            strcpy(price,"350");
            break;
        case 3:
            strcpy(train_no,"12346");
            strcpy(train_name,"Shatabdi Express");
            strcpy(time,"11:00 AM");
            strcpy(price,"755");
            break;
        case 4:
            strcpy(train_no,"12461");
            strcpy(train_name,"Vande Bharat Express");
            strcpy(time,"12:00 PM");
            strcpy(price,"1200");
            break;
        default:
            printf("\033[31mInvalid choice\033[0m\n");
            break;
    }
    printf("Enter date of journey(dd/mm/yyyy): ");
    scanf("%s",date);    
    dashboard();   
}
void cancel_ticket(){
    system("cls");
    printf("\033[34mCancelling Ticket\033[0m\n");
    printf("%-10s%-25s%-10s%-10s%-10s\n","Train No.","Train name","Time","Price","Date");
    printf("-----------------------------------------------------------------\n");
    printf("%-10s%-25s%-10s%-10s%-10s\n",train_no,train_name,time,price,date);
    printf("\nAre you sure you want to cancel this ticket? (1 for Yes, 0 for No): ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        strcpy(train_no,"");
        strcpy(train_name,"");
        strcpy(time,"");
        strcpy(price,"");
        strcpy(date,"");
        printf("\033[32mTicket cancelled successfully!\033[0m\n");
    }
    printf("\nPress any number to continue...");
    int temp;
    scanf("%d",&temp);
    dashboard();
}
void view_ticket(){
    system("cls");
    printf("\033[34mViewing Ticket\033[0m\n");
    printf("%-10s%-25s%-10s%-10s%-10s\n","Train No.","Train name","Time","Price","Date");
    printf("-----------------------------------------------------------------\n");
    printf("%-10s%-25s%-10s%-10s%-10s\n",train_no,train_name,time,price,date);
    int i;
    printf("\nPress any number to continue...");
    scanf("%d",&i);
    dashboard();
}