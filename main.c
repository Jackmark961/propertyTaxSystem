#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>


void refresh();
void addProperty(void);
void addCustomer();
void calculateTax();
void payTax();
void printPaid();
void printTrans();
void printProp();

char propType[5][30] = {
    "Plain-Ground",
    "Building with tiles/Sheets",
    "Houses with RCC molds",
    "Small Commercial Building",
    "SEZ buildings"};

char usage[2][10] = {"Self","Rented",};


typedef struct
{
    int id;
    int length;
    int breadth;
    int sqft;
    int stories;
    float index;
    char usage[5];
    float tax;
    long int builtUp;
    char type[30];
} property;

typedef struct
{
    char name[20];
    char address[50];
    long int phone;
    char email[20];
    int propId;
} owner;

typedef struct
{
    char name[20];
    int id;
    char type[30];
    int dimension;
    char usage[5];
    float tax;
} printTax;

void main()
{
    //to refresh the test files;
    // refresh();
    int ch;
    while(1)
    {
        system("clear");
        printf("======= PROPERTY TAX SYSTEM ======");
        printf("\n\n\t1. Add property");
        printf("\n\t2. Add owner");
        printf("\n\t3. Calculate tax");
        printf("\n\t4. Pay tax");
        printf("\n\t5. Print tax collected");
        printf("\n\t6. Print all the Properties Registered");
        printf("\n\t7. Print all Transactions");
        printf("\n\t8. Exit");
        printf("\n\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);
        
        switch (ch)
        {
        case 1:
            system("clear");
            addProperty();
            break;

        case 2:
            system("clear");
            addCustomer();
            break;

        case 3:
            system("clear");
            calculateTax();
            break;

        case 4:
            system("clear");
            payTax();
            break;

        case 5:
            system("clear");
            printPaid();
            break;

        case 6:
            system("clear");
            printProp();
            break;

        case 7:
            system("clear");
            printTrans();
            break;

        case 8:
            system("clear");
            printf("Thank you\n");
            exit(0);
            break;
        
        default:
            printf("\n\nIncorrect response!!\n\n");
            system("clear");

            break;
        }
    }

}

void addProperty()
{
    property info;

    printf("====== ADDING PROPERTY DETAILS ======");
    printf("\n\n");
    printf("Enter the length of the property in ft : ");
    scanf("%d",&info.length);
    printf("\nEnter the breadth of the property in ft : ");
    scanf("%d",&info.breadth);
    
    info.sqft = info.length*info.breadth;

    int type = 100; //validating the type of property
    while(!(type>= 1 && type <=5))
    {
        printf("\nChoose the type of your property");
        printf("\n1. Plain-Ground");
        printf("\n2. Building with tiles/sheet");
        printf("\n3. Houses with RCC molds");
        printf("\n4. Small commercial building");
        printf("\n5. SEZ building");
        printf("\n\nEnter the choice : ");
        scanf("%d",&type);
        if(type<1 && type>6)
        {
            printf("\nIncorrect choice!!!");
            printf("\n\nPlease choose from the above list correctly.");
            printf("\nEnter the number corresponding to your building type..");
            sleep(4);

        }
    }
    type = type-1;
    strcpy(info.type,propType[type]);

    //handling values according to its property type;
    int subtype;
    if(type == 0)
    {
        info.stories = 0;
        info.builtUp = 0;
        info.index = 0.0;
        strcpy(info.usage,usage[0]);
        info.tax = info.sqft * 1;

    }
    if(type == 1)
    {
        
        info.stories = 1;
        info.builtUp = info.sqft;
        info.index = 0.0;
        printf("\nIs this Property");
        printf("\n1. Owned\n2. Rented");
        printf("\nEnter the choice : ");
        scanf("%d",&subtype);
        if(!(subtype == 1 || subtype == 2))                 //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;

        }
        strcpy(info.usage,usage[subtype-1]);
        
        if(subtype == 1)
        {
            info.tax = 1.5*info.builtUp;
        }
        else
        {
            info.tax = 1.75*info.builtUp;
        }

    }
    if(type == 2)
    {
        printf("\nEnter the number of floors (should not exceed 3 floors) : ");
        scanf("%d",&info.stories);

        if(info.stories > 3 || info.stories < 0)                 //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }
        info.builtUp = info.stories*info.sqft;
        info.index = 0.0;

        printf("\nIs this Property");
        printf("\n1. Owned\n2. Rented");
        printf("\nEnter the choice : ");
        scanf("%d",&subtype);

        if(!(subtype == 1 || subtype == 2))                  //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }
        strcpy(info.usage,usage[subtype-1]);
        
        if(subtype == 1)
        {
            info.tax = 2*info.builtUp;
        }
        else
        {
            info.tax = 2.25*info.builtUp;
        }

    }
    if(type == 3)
    {
        printf("\nEnter the number of floors (should not exceed 5 floors) : ");
        scanf("%d",&info.stories);

        if(info.stories > 5 || info.stories < 0)                 //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }
        info.builtUp = info.stories*info.sqft;
        printf("\nIs this Property");
        printf("\n1. Owned\n2. Rented");
        printf("\nEnter the choice : ");
        scanf("%d",&subtype);
        if(!(subtype == 1 || subtype == 2))                  //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }
        strcpy(info.usage,usage[subtype-1]);
        
        printf("\nEnter the locality index (should be between 1.0 to 2.0) : ");
        scanf("%f",&info.index);
        
        if(info.index < 1.0 || info.index > 2.0)                 //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }
        info.tax = info.index*3.5*info.builtUp;

    }
    if(type == 4)
    {
        printf("\nEnter the number of floors (should be within 5 to 25) : ");
        scanf("%d",&info.stories);


        if(info.stories < 5 || info.stories > 25)                 //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }
        info.builtUp = info.stories*info.sqft;
        printf("\nIs this Property");
        printf("\n1. Owned\n2. Rented");
        printf("\nEnter the choice : ");
        scanf("%d",&subtype);

        if(!(subtype == 1 || subtype == 2))                  //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }

        strcpy(info.usage,usage[subtype-1]);
        
        printf("\nEnter the Economic index (should be between 2.0 to 2.5) : ");
        scanf("%f",&info.index);
        if(info.index < 2.0 || info.index > 2.5)                 //validation
        {
            printf("\n\nINVALID INPUT..");
            printf("\nPress enter to go back...");
            getchar();
            getchar();
            return;
        }
        info.tax = info.index*3.5*info.builtUp;
    }

    // printf("\n\nProperty data added successfully!!");
    printf("\n\nProperty Registered Successfully!!");


    FILE *fp;                               //incrementing the khataID value
    fp = fopen("khataId.txt","r");
    int temp,id;
    fscanf(fp,"%d",&temp);
    id = temp;
    temp = temp+1;
    freopen("khataId.txt","w",fp);
    fprintf(fp,"%d",temp);
    fclose(fp);
    
    
    printf("\n\n\nProperty id will be auto-generated by the system\n");
    printf("\nYour Property ID : %d\n\n",id);
    info.id = id;

    fp = fopen("property.txt","a");
    fwrite(&info,sizeof(property),1,fp);
    fclose(fp);
    
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}

void addCustomer()
{

    int khataID;
    int found = 0;
    int exit;
    property data;

    owner info;
    printf("====== ADD PROPERTY OWNER ======");

    printf("\n\nEnter Khata ID : ");
    scanf("%d",&khataID);
    FILE *fp;
    fp = fopen("property.txt","r");

    while(fread(&data,sizeof(property),1,fp))
    {
        if(khataID == data.id)
        {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("\nNo record found please try again...");
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        return;
    }
    
    owner Odata;
    int foundOwner = 0;
    fp = fopen("customer.txt","r");
    
    while(fread(&Odata,sizeof(owner),1,fp))
    {
        if(khataID == Odata.propId)
        {
            foundOwner = 1;
            break;
        }
    }
    fclose(fp);

    if(foundOwner)
    {
        printf("\n\nProperty is already Owned!!");
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        return;
    }
    printf("\nEnter your name : ");
    scanf(" %[^\n]s",info.name);
    printf("\nEnter address : ");
    scanf("%s",info.address);
    printf("\nEnter the mobile number : ");
    scanf("%ld",&info.phone);
    printf("\nEnter email id : ");
    scanf("%s",info.email);

    info.propId = khataID;

    fp = fopen("customer.txt","a");
    fwrite(&info,sizeof(owner),1,fp);
    fclose(fp);
    printf("\n\nData stored successfully!!");
    printf("\nPress enter to continue...");

    getchar();
    getchar();
    return;
}

void calculateTax()
{
    int id;
    printf("====== CALCULATE TAX ======");
    printf("\nEnter your property ID : ");
    scanf("%d",&id);
    char name[20];
    int found = 0;
    FILE *fp;
    fp = fopen("property.txt","r");
    property pdata;
    while(fread(&pdata,sizeof(property),1,fp))
    {
        if(pdata.id == id)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\nNo record found for this Property ID!!!");
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        return;
    }

    found = 0;
    fp = fopen("customer.txt","r");
    owner odata;
    while(fread(&odata,sizeof(owner),1,fp))
    {
        if(odata.propId == id)
        {
            found = 1;
            printf("Hello %s!",odata.name);
            printf("\n\nYour Property details are :\n");
            printf("\nProperty ID        : %d",id);
            printf("\nProperty Type      : %s",pdata.type);
            printf("\nProperty Dimension : %dsqft",pdata.sqft);
            printf("\nProperty usage     : %s",pdata.usage);
            printf("\n\nYour payable tax will be %.3f",pdata.tax);

            printf("\n\nPress enter to continue...");
            getchar();
            getchar();
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(!found)
    {
        printf("\nThis property has no owner");
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        return;
    }
}


void payTax()
{
    int id;
    printf("====== PAY TAX ======");
    printf("\nEnter your property ID : ");
    scanf("%d",&id);
    char name[20];
    int found = 0;
    FILE *fp;
    fp = fopen("property.txt","r");
    property pdata;
    while(fread(&pdata,sizeof(property),1,fp))
    {
        if(pdata.id == id)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\nNo record found for this Property ID!!!");
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        return;
    }

    found = 0;
    fp = fopen("customer.txt","r");
    owner odata;
    while(fread(&odata,sizeof(owner),1,fp))
    {
        if(odata.propId == id)
        {
            found = 1;
            printf("Hello %s!",odata.name);
            printf("\nYour Property details are :\n");
            printf("\nProperty ID        : %d",id);
            printf("\nProperty Type      : %s",pdata.type);
            printf("\nProperty Dimension : %dsqft",pdata.sqft);
            printf("\nProperty usage     : %s",pdata.usage);
            printf("\n\nYour payable tax will be %.3f",pdata.tax);  
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(!found)
    {
        printf("\nThis property has no owner");
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        return;
    }
    char ch;
    printf("\n\nPlease confirm the transaction [y/n] : ");
    scanf("%s",&ch);
    if(ch == 'n' || ch == 'N')
    {
        printf("\nPlease pay your tax as soon as possible..");
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        return;
    }

    printf("\nTransaction Complete!!!\n");
    printf("\nPress enter to continue...");
    getchar();
    getchar();
    printf("printing payment bill..");
    system("clear");

    printf("\n\n-----------------------------------------------------\n\n");
    printf("\nName               : %s",odata.name);
    printf("\nProperty ID        : %d",pdata.id);
    printf("\nProperty Type      : %s",pdata.type);
    printf("\nProperty Dimension : %dsqft",pdata.sqft);
    printf("\nProperty usage     : %s",pdata.usage);
    printf("\nAmount paid        : %.3f",pdata.tax);
    printf("\n\n\n-----------------------------------------------------\n");

    printTax data;
    strcpy(data.name,odata.name);
    data.id = pdata.id;
    strcpy(data.type,pdata.type);
    data.dimension = pdata.sqft;
    strcpy(data.usage,pdata.usage);
    data.tax = pdata.tax;


    //writing transaction into a file
    fp = fopen("transaction.txt","a");
    fwrite(&data,sizeof(printTax),1,fp);
    fclose(fp);

    fp = fopen("total.txt","r");
    float temp;
    fscanf(fp,"%f",&temp);
    freopen("total.txt","w",fp);
    temp = temp+data.tax;
    fprintf(fp,"%f",temp);
    fclose(fp);

    printf("\nPress enter to continue...");
    getchar();
}

void printPaid()
{
    FILE *fp;
    fp = fopen("total.txt","r");
    float tax;
    fscanf(fp,"%f",&tax);
    fclose(fp);

    printf("-----------------------------------------------------\n\n");
    printf("Total Tax collected by the Corporation : %f Rupees\n\n",tax);
    printf("-----------------------------------------------------\n");
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}

void printTrans()
{
    printf("====== ALL TRANSACTIONS ======\n");
    FILE *fp;
    printTax info;
    fp = fopen("transaction.txt","r");
    while(fread(&info,sizeof(printTax),1,fp))
    {
        printf("\n-----------------------------------------------------");
        printf("\nName               : %s",info.name);
        printf("\nProperty ID        : %d",info.id);
        printf("\nProperty Type      : %s",info.type);
        printf("\nProperty Dimension : %dsqft",info.dimension);
        printf("\nProperty usage     : %s",info.usage);
        printf("\nAmount Received    : %.3f",info.tax);
    }
    fclose(fp);
    printf("\n-----------------------------------------------------\n\n");

    printf("\nPress enter to continue...");
    getchar();
    getchar();
}

void printProp()
{
    printf("====== ALL PROPERTIES ======\n");
    FILE *fp;
    fp = fopen("property.txt","r");
    property info;
    while(fread(&info,sizeof(property),1,fp))
    {
        printf("\n-----------------------------------------------------");
        printf("\nProperty ID        : %d",info.id);
        printf("\nProperty Type      : %s",info.type);
        printf("\nProperty Lenght    : %d ft",info.length);
        printf("\nProperty Breadth   : %d ft",info.breadth);
        printf("\nProperty Dimension : %d sqft",info.sqft);
        printf("\nNo. of Floors      : %d",info.stories);
        printf("\nProperty Usage     : %s",info.usage);
        printf("\nIndex              : %.1f",info.index);
        printf("\nPayable tax        : %.3f",info.tax);
    }

    printf("\n-----------------------------------------------------\n\n");
    fclose(fp);

    printf("\nPress enter to continue...");
    getchar();
    getchar();
}


                                                        // rewrite total.txt to 0 inside refresh
//to refresh the text files;
void refresh()
{
    FILE *fp;
    fp = fopen("customer.txt","w");
    freopen("property.txt","w",fp);
    freopen("transaction.txt","w",fp);
    freopen("khataId.txt","w",fp);
    int temp = 1;
    fprintf(fp,"%d",temp);
    fclose(fp);
    fp = fopen("total.txt","w");
    float zero = 0;
    fprintf(fp,"%f",zero);
    fclose(fp);
}