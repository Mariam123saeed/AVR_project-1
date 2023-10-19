#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define password  1234


typedef struct patient {
   int age,ID,date;
   char gender,name[20];
   struct patient *next;
}Patient;
Patient *head=NULL,*tail=NULL;
Patient *arr[5]={NULL};
//to check if ID exist or not
Patient *id_Search(long id_num)
{
   Patient *ptr;
   ptr=head;
   while(ptr!=NULL)
   {
       if(ptr->ID==id_num)
       {
         return ptr;
       }
       ptr=ptr->next;
   }
   return NULL;
}
// adding new patient
void newPatient (void);
// view patient record
void Veiw_pat (void);
// view old file
void Old_File (void);
// edit patient record
void Edit_pat (void);
// veiw available slots
void avlble_slot (void);
// check for available slot
void check_Res (long id_num);
// reserve a date
void Reservation (long id_num,int choise);
// cancel reservation
void cancl_rsrv(long id_num,int choise);
// veiw today reservation for user
void vew_rsrv (long id_num);
void admin ();
void user ();




int main()
{
   int mode,order,order1,choise;
   long pass,id_num;
   
   printf("If you want Admin mode Enter:1\n");
   printf("If you want User mode Enter:2\n");
   printf("If you want to Exit Enter :3\n");
   scanf("%d",&mode);
   switch (mode)
   {
   case 1:// Admin mode
      printf("WELCOME ADMIN...\n");
      printf("Please Enter your Password:\n");
      scanf("%ld",&pass);
      if(pass==password)
      {
         admin();
         
      }
      else if(pass!=password)
      {
         
         for(int i=0;i<2;i++)
         {
            printf("Please enter a password again\n");
            scanf("%d",&pass);
            if(pass==password)
          {
          admin();
          }
        }
      }
           if(pass!=password)
          {
            printf("Incorrect password for 3  times,No more available tries\n");
            break;
          }
      //end of Admin mode
      main(); //to go back to the top
      break;

          
         
     
      
     case 2://User mode
            printf("WELCOME USER....\n");
            
           user ();
           main();
           break;
    
   //end of USER mode
   
   }
  
  
    return 0;
}

//******************
//1- add new patient (new node)
void newPatient(void)
{
   Patient *ptr;
   long id_num;
   ptr=(Patient*)malloc(sizeof(Patient));
   printf("Please Enter ID to add new patient : \n ");
   scanf("%ld",&id_num);
   if(ptr!=NULL)
   {  
     
       if(id_Search(id_num)==NULL)
      {
         ptr->ID=id_num;
         
         printf("Please Enter Paitent Name :");
			scanf("%s",&(ptr->name));
         printf("Please Enter Paitent Age : ");
			scanf("%d",&(ptr->age));
			printf("Please Enter Paitent M for Males and F for Females : ");
			scanf(" %c",&(ptr->gender));
			
        
        
        
         // there is no reservation yet
         if(head==NULL)
         {
            head=ptr;
            tail=ptr;
            ptr->next=NULL;
         }
         // in case of  reservation
         else 
         {
            tail->next=ptr;
            tail=ptr;
            tail->next=NULL;
         }
      }
      else if(id_Search(id_num)!=NULL)
      {
         printf("this patient is already Exist...\n");
      }
    
   
   }
   

}

//2-veiw patient record
void Veiw_pat(void)
{
   Patient *ptr;
   long id_num;
    
   printf("Please Enter ID to Veiw patient file : \n ");
   scanf("%ld",&id_num);
   if(id_Search(id_num) ==NULL)
   {
     printf("This patient is not Registered...\n");
   }
   else if(id_Search(id_num) !=NULL)
   {
     ptr=id_Search(id_num);
     printf("patient ID is : %d\n",ptr->ID);
     printf("Patient name is : %s\n",(ptr->name));
     printf("Patient age is : %d\n",ptr->age);
     printf("Patient gender is : %c\n",ptr->gender);
     printf("Patient date is : %d\n",ptr->date);

   }

}

//3-view old file
void Old_File(void)
{
   Patient *ptr;
   long id_num;
   scanf("%d",&id_num);
   if(id_Search(id_num) ==NULL)
   {
   printf("This patient is not Registered...\n");
   }
   else if(id_Search(id_num) !=NULL)
   { 
     ptr=id_Search(id_num);
     printf("patient ID is : %d\n",ptr->ID);
     printf("Patient name is : %s\n",ptr->name);
     printf("Patient age is : %d\n",ptr->age);
     printf("Patient gender is : %c\n",ptr->gender);
     printf("Patient date is : %d\n",ptr->date);

   }

}

//4-edit patient info
void Edit_pat(void)
{
   Patient *ptr;
   long id_num;
   int choise;
   printf("To veiw patient file enter ID ...\n");
   scanf("%d",&id_num);
  
   if(id_Search(id_num) !=NULL)
   {
      Old_File();
      //to edit info:at first make ptr point to pat ID
      ptr=id_Search(id_num);
      printf("Please enter  new patient name :");
      scanf("%s",&(ptr->name));
      printf("Please Enter new gender M for Males and F for Females : ");
		scanf(" %c",&(ptr->gender));
      printf("Please enter new patient age : ");
      scanf("%d",&(ptr->age));
      printf("Please enter patient new date : \n");
      avlble_slot();
      scanf("%d",&choise);
      check_Res(id_num);
      Reservation (id_num,choise);
   }
    else if(id_Search(id_num)==NULL)
   {
       printf("This patient is not Registered...\n");
   }

}

// 5-veiw available slots
void avlble_slot(void)
{
   if(arr[0]==NULL)
   {
      printf("The First date from 2:00 PM to 2:30 PM to choose ENTER :1\n");
   }
   if(arr[1]==NULL)
   {
      printf("The Second date from 2:30 PM to 3:00 PM to choose ENTER :2\n");
   }
   if(arr[2]==NULL)
   {
      printf("The Third date from 3:00 PM to 3:30 PM to choose ENTER :3\n");
   }
   if(arr[3]==NULL)
   {
      printf("The Fourth date from 4:00 PM to 4:30 PM to choose ENTER :4\n");
   }
   if(arr[4]==NULL)
   {
      printf("The Fifth date from 4:30 PM to 5:00 PM to choose ENTER :5\n");
   }
    
}

//6- check for available slot
void check_Res(long id_num)
{
   Patient *ptr;
   long choise;
   ptr=id_Search(id_num);
    
  
   if(ptr!=NULL)//  to check if the id exist or not 
   {
      if(arr[0]!=NULL)//to check if the slot reserved or not
      {
         printf("This date is already reserved..\n.");

      }
      if(arr[1]!=NULL)
      {
         printf("This date is already reserved...\n");

      }
        if(arr[2]!=NULL)
      {
         printf("This date is already reserved...\n");

      }
        if(arr[3]!=NULL)
      {
         printf("This date is already reserved...\n");

      }
        if(arr[4]!=NULL)
      {
         printf("This date is already reserved...\n");

      }
     
   }
    
    
}

// 7-reserve a date
void Reservation (long id_num,int choise)
{
   Patient *ptr;
   if(id_Search(id_num)!=NULL)
   {
      if(choise==1)
      {
         ptr->date=choise;
         arr[0]=ptr;
      }
      else if(choise==2)
      {
         ptr->date=choise;
         arr[1]=ptr;
      }
       else if(choise==3)
      {
         ptr->date=choise;
         arr[2]=ptr;
      }
       else if(choise==4)
      {
         ptr->date=choise;
         arr[3]=ptr;
      }
       else if(choise==5)
      {
         ptr->date=choise;
         arr[4]=ptr;
      }
   }
  

}


// 8-cancel reservation
void cancl_rsrv(long id_num,int choise)
{
   Patient *ptr;
   ptr=id_Search(id_num);
   ptr->date=choise;
    
       if(ptr->date==1)
   {
       arr[0]=NULL;//this date becomes available again
       free(ptr);
   }
       if(ptr->date==2)
   {
      arr[1]==NULL;
      free(ptr);
   }
      if(ptr->date==3)
   {
      arr[2]==NULL;
      free(ptr);
   }
      if(ptr->date==4)
   {
      arr[3]==NULL;
      free(ptr);
   }
      if(ptr->date==5)
   {
      arr[4]==NULL;
      free(ptr);
   }

  
  
}

// 9-veiw today reservation for user
void vew_rsrv (long id_num)
{
  Patient *ptr;
 
   
   
      if(arr[0]!=NULL)
      {
         printf("The paitent Reserve Slot Number : %d\n",arr[0]->date);
         printf("ID of patient : %d\n",arr[0]->ID);
      }
       if(arr[1]!=NULL)
      {
         printf("The paitent Reserve Slot Number : %d\n",arr[1]->date);
         printf("ID of patient : %d\n",arr[1]->ID);
      }
        if(arr[2]!=NULL)
      {
         printf("The paitent Reserve Slot Number : %d\n",arr[2]->date);
         printf("ID of patient : %d\n",arr[2]->ID);
      }
        if(arr[3]!=NULL)
      {
         printf("The paitent Reserve Slot Number : %d\n",arr[3]->date);
         printf("ID of patient : %d\n",arr[3]->ID);
      }
        if(arr[4]!=NULL)
      {
         printf("The paitent Reserve Slot Number : %d\n",arr[4]->date);
         printf("ID of patient : %d\n",arr[4]->ID);
      }
   
      
  
    
}

//admin mode:
void admin ()
{
   int order,order1,choise;
   long pass,id_num;
     while (1)
         {

           printf("To adding new patient ENTER : 1\n");
           printf("To edit patint record ENTER : 2\n");
           printf("To reserve a slot with a doctor ENTER : 3\n");
           printf("To cancel reservation ENTER : 4\n");
           printf("To Go back ENTER : 5\n");
            printf("To veiw today reservation Enter : 6\n");
           scanf("%d",&order);
           switch (order)
           {
           case 1:
           newPatient();
           break;
           case 2:
           Edit_pat();
           break;
           case 3:
           printf("Please Enter patient ID...\n");
           scanf("%d",&id_num);
           avlble_slot();
            if(id_Search(id_num)!=NULL)
					 {
					    printf("Please Enter The Date :\n ");
					    scanf("%d",&choise);
					    check_Res (id_num);
					    Reservation(id_num,choise);
					     
					 } 
				  else if (id_Search(id_num)==NULL)
					 {
						 printf("This ID Is Not Regestered -_-\n");
					 }
           break;
            case 4:
           printf("Please Enter patient ID...\n");
           scanf("%d",&id_num);
           if(id_Search(id_num)!=NULL)
					{
					    printf("Please Enter The Date you want to cancel :\n ");
					    scanf("%d",&choise);
                   cancl_rsrv(id_num,choise);
               }
               else if (id_Search(id_num)==NULL)
					{
						printf("This ID Is Not Regestered -_-\n");
					}
               break;
                case 6:
                  vew_rsrv(id_num);
                  break;

           
            //case 5:
          
            //break;
          
           }
           if(order==5)
           {
            break;
           }
        }

}

// user mode:
void user()
{
   int order,order1;
   long id_num;
     while(1)
           {
               printf("To veiw patient record ENTER : 1\n");
               printf("To veiw today reservation Enter : 2\n");
               printf("To Go back ENTER : 3\n");
               scanf("%d",&order1);
               switch (order1)
               {
               case 1:
                  Veiw_pat();
                  break;
               case 2:
                  vew_rsrv(id_num);
                  break;
               
               //case 3:
               
                  //break;
                 
               }
               if(order1==3)
               {
                  break;
               }
           }
}





    
