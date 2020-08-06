#include<stdio.h>
#include<string.h>
struct customer
{
	int account_number;
	char cust_name[55];
	char gender[7];
	int age;
	int cnic;
	float balance;
	
};
int main()
{
	FILE *record;
	FILE *next_account_number;
	int choice,key;
	customer cu;
	printf("\nPress 1 for new Entery.");
	printf("\nPress 2 for viewing records.");
	printf("\nPress 3 for search particular record.");
	printf("\n\nEnter your Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				int i = 1;
				while(i == 1)
				{
					record = fopen("bank_database.txt","a");
					next_account_number = fopen("Account_number.txt","w");
					printf("\nName:");
					scanf("%s",&cu.cust_name);
					printf("\nGender:");
					scanf("%s",&cu.gender);
					printf("\nAge:");
					scanf("%d",&cu.age);
					printf("\nCNIC:");
					scanf("%d",&cu.cnic);
					printf("\nBalance:");
					scanf("%f",&cu.balance);
					fscanf(next_account_number,"%d",&key);
					fprintf(record, "%d %s %s %d %d %.2f\n",key,&cu.cust_name,&cu.gender,cu.age,cu.cnic,cu.balance);
					key = key + 2;
					fprintf(next_account_number,"%d",key);
					fclose(record);
					fclose(next_account_number);
					printf("\nDo you want to enter another record(1/0):");
					scanf("%d",&i);
				}
				break;
			}
		case 2:
			{
				char ch;
				record = fopen("bank_database.txt","r");
				printf("Account# - Name - Gender - Age - CNIC - Balance\n");
				while(fscanf(record ,"%d %s %s %d %d %f",&key,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.balance) != EOF)
				{
					printf("%d-%s-%s-%d-%d-%.2f\n",key,cu.cust_name,cu.gender,cu.age,cu.cnic,cu.balance);
				}
				fclose(record);
				break;
			}
		case 3:
			{
				printf("\nSearch by Account#(1)\nName(2)\nCNIC(3)\nGender(4):");
				printf("\n\nEnter Your Choice: ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						{
							int ea;
							printf("Enter Account#:");
							scanf("%d",&ea);
							record = fopen("bank_database.txt","r");
							while(fscanf(record ,"%d %s %s %d %d %f",&key,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.balance) != EOF)
							{
								if(key == ea)
								{
									printf("Account# - Name - Gender - Age - CNIC - Balance\n");
									printf("%d-%s-%s-%d-%d-%.2f\n",key,&cu.cust_name,&cu.gender,cu.age,cu.cnic,cu.balance);
								}
							}
							fclose(record);
							break;	
						}
					case 2:
						{
							char name[55];
							printf("Enter Name:");
							scanf("%s",&name);
							record = fopen("bank_database.txt","r");
							printf("Account# - Name - Gender - Age - CNIC - Balance\n");
							while(fscanf(record ,"%d %s %s %d %d %f",&key,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.balance) != EOF)
							{
								if(strcmp(name,cu.cust_name) == 0)
								{
									printf("%d-%s-%s-%d-%d-%.2f\n",key,&cu.cust_name,&cu.gender,cu.age,cu.cnic,cu.balance);
								}
							}
							fclose(record);
							break;
						}
					case 3:
						{
							int ea;
							printf("Enter CNIC#:");
							scanf("%d",&ea);
							record = fopen("bank_database.txt","r");
							while(fscanf(record ,"%d %s %s %d %d %f",&key,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.balance) != EOF)
							{
								if(cu.cnic == ea)
								{
									printf("Account# - Name - Gender - Age - CNIC - Balance\n");
									printf("%d-%s-%s-%d-%d-%.2f\n",key,&cu.cust_name,&cu.gender,cu.age,cu.cnic,cu.balance);
								}
							}
							fclose(record);
							break;
						}
					case 4:
						{
							char name[55];
							printf("Enter Gender:");
							scanf("%s",&name);
							record = fopen("bank_database.txt","r");
							printf("Account# - Name - Gender - Age - CNIC - Balance\n");
							while(fscanf(record ,"%d %s %s %d %d %f",&key,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.balance) != EOF)
							{
								if(strcmp(name,cu.gender) == 0)
								{
									printf("%d-%s-%s-%d-%d-%.2f\n",key,&cu.cust_name,&cu.gender,cu.age,cu.cnic,cu.balance);
								}
							}
							fclose(record);
							break;
						}
				}
				break;
			}	
	}
}
