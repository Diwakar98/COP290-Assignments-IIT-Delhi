#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
struct Event{
     float time;
     float arrivalTime;
     float serviceTime;
     float completionTime;
     float idleTime;
     int tellerno;
     int customerno;
     int action;/*  1=Newly arrived Customer
                    2=Customer Service Completed
                    3=Teller Completed Serving
                    4=Teller completed idle time*/
     struct Event* next;
     struct Event* prev;
};
struct EventQueue {
     struct Event* head;
     struct Event* tail;
     int count;
};
struct Customer{
     int customerno;
     float arrivalTime;
     float completionTime;
     struct Customer* next;
};
struct tellerQueue{
     struct Customer* head;
     struct Customer* tail;
     float idleTime;
     int tellerno;
     int count;
};
struct Teller{
     float idleTime;
     int tellerno;
     struct tellerQueue* tellerQueue;
};
void addcustomer(struct tellerQueue** list, float arrivalTime,int customerno){
     struct Customer* newnode = (struct Customer*) malloc(sizeof(struct Customer));
     newnode->arrivalTime=arrivalTime;
     newnode->customerno=customerno;
     newnode->next=NULL;
     if ((*list)->head == NULL) {
          (*list)->head = (struct Customer*) malloc(sizeof(struct Customer));
          (*list)->tail = (struct Customer*) malloc(sizeof(struct Customer));
          (*list)->head = newnode;
          (*list)->tail = newnode;
          (*list)->count = 1;
     }
     else{
          ((*list)->tail)->next = newnode;
          (*list)->tail = newnode;
          (*list)->count = ((*list)->count)+1;
     }
     return;
}
struct Customer* rmvCustomer(struct tellerQueue** list){
     if((*list)->head == NULL){
          return NULL;
     }
     else{
          struct Customer* newnode = (struct Customer*) malloc(sizeof(struct Customer));
          newnode = (*list)->head;
          (*list)->head = ((*list)->head)->next;
          (*list)->count--;
          return newnode;
     }
}
void printCustomerQueue(struct tellerQueue** list,int tellerno){
     struct Customer* node = (*list)->head;
     printf("Teller %d:\n", tellerno);
     while(node!=NULL){
          printf("Customer %d arrived at t = %f\n",node->customerno,node->arrivalTime);
          node=node->next;
     }
}
void printCustomerQueueSingleLine(struct tellerQueue** list){
     struct Customer* node = (*list)->head;
     while(node!=NULL){
          printf("Customer %d arrived at t = %f\n",node->customerno,node->arrivalTime);
          node=node->next;
     }
}
void printEventQueue(struct EventQueue** list){
     struct Event* node = (*list)->head;
     printf("<-------------EVENT----------->\n");
     while(node!=NULL){
          if(node->action==1){
               printf("Customer %d arrived at t = %f\n", node->customerno, node->arrivalTime);
          }
          else if(node->action==2){
               printf("Customer %d Service Completed at t = %f, serviceTime = %f\n", node->customerno, node->time, node->serviceTime);
          }
          else if(node->action==3){
               printf("Teller %d completed service at t = %f, serviceTime = %f\n",node->tellerno,node->time,node->serviceTime);
          }
          else if(node->action==4){
               printf("Teller %d completed idle time of %f mins at t = %f\n",node->tellerno,node->idleTime,node->time);
          }
          node = node->next;
     }
     printf("<-------------EVENT----------->\n");
}
void addevent(struct EventQueue** list, float arrivalTime,float serviceTime,int action,int tellerno,float idleTime,float time,float completionTime,int customerno){
     struct Event* newnode = (struct Event*) malloc(sizeof(struct Event));
     newnode->arrivalTime=arrivalTime;
     newnode->serviceTime=serviceTime;
     newnode->action=action;
     newnode->idleTime=idleTime;
     newnode->tellerno=tellerno;
     newnode->time=time;
     newnode->customerno=customerno;
     newnode->completionTime=completionTime;
     newnode->next=NULL;
     if ((*list)->head == NULL) {
          (*list)->head = (struct Event*) malloc(sizeof(struct Event));
          (*list)->tail = (struct Event*) malloc(sizeof(struct Event));
          (*list)->head = newnode;
          (*list)->tail = newnode;
          (*list)->count = 1;
     }
     else{
          struct Event* node = (*list)->head;
          while(node!=NULL){
               float x = node->time;
               float y = time;
               if(x>y){
                    if(node==(*list)->head){
                         node->prev = newnode;
                         newnode->next = node;
                         (*list)->head = newnode;
                    }
                    else{
                         newnode->next = node;
                         (node->prev)->next = newnode;
                         newnode->prev = node->prev;
                         node->prev = newnode;
                    }
                    break;
               }
               node = node->next;
          }
          if(node==NULL){
               newnode->prev = (*list)->tail;
               ((*list)->tail)->next = newnode;
               (*list)->tail = newnode;
          }
          (*list)->count = ((*list)->count)+1;
     }
     return;
}
struct Event* rmvEvent(struct EventQueue** list){
     if((*list)->head == NULL){
          return NULL;
     }
     else{
          struct Event* newnode = (struct Event*) malloc(sizeof(struct Event));
          newnode = (*list)->head;
          (*list)->head = ((*list)->head)->next;
          (*list)->count--;
          if(newnode->action==1){
               // printf("New customer arrived at t = %f\n", newnode->arrivalTime);
          }
          else if(newnode->action==2){
               // printf("Customer's Service Completed t = %f\n", newnode->serviceTime);
          }
          else if(newnode->action==3){
               // printf("Teller %d completed service\n", newnode->tellerno);
          }
          else if(newnode->action==4){
               // printf("Teller %d completed idle time of %d mins\n",newnode->tellerno,newnode->idleTime);
          }
          return newnode;
     }
}
bool isempty(struct EventQueue** list){
     if((*list)->head==NULL){
          return true;
     }
     else{
          return false;
     }
}
int smallestline(struct tellerQueue* tellerQueue[], int nooftellers){
     int min=100;
     int minqueue=0;
     for(int i=0; i<nooftellers; i++){
          // printf("=%d =%d =%d\n", tellerQueue[i]->count,tellerQueue[i]->tellerno,tellerQueue[i]->idleTime);
          if(tellerQueue[i]->count < min){
               // printf("X\n" );
               min=tellerQueue[i]->count;
               minqueue=i;
          }
     }
     return minqueue;
}
void merge(float arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    float L[n1];
    float R[n2];
    for (int i=0; i<n1; ++i)
       L[i] = arr[l + i];
    for (int j=0; j<n2; ++j)
       R[j] = arr[m + 1+ j];
    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
       if (L[i] <= R[j])
       {
            arr[k] = L[i];
            i++;
       }
       else
       {
            arr[k] = R[j];
            j++;
       }
       k++;
    }
    while (i < n1)
    {
       arr[k] = L[i];
       i++;
       k++;
    }
    while (j < n2)
    {
       arr[k] = R[j];
       j++;
       k++;
    }
}
void sort(float arr[], int l, int r)
{
    if (l < r)
    {
       int m = (l+r)/2;
       sort(arr, l, m);
       sort(arr , m+1, r);
       merge(arr, l, m, r);
    }
}
void simulateMultiLine(struct EventQueue* list,int noofcustomers, int nooftellers, float simulationTime, float averageServiceTime){
     srand ( time(NULL) );
     float clockml=0.0;
     struct tellerQueue* tellerQueue[nooftellers];
     float timing[noofcustomers];
     float totaltime=0.0;
     float maxwaittime = 0.0;
     float totalTellerServiceTime[nooftellers];
     float totalTellerIdleTime[nooftellers];
     int noofcustomerserved = 0;
     for(int i=0; i<nooftellers; i++){
          tellerQueue[i]=(struct tellerQueue*)malloc(sizeof(struct tellerQueue));
          (tellerQueue[i])->tellerno = i;
          (tellerQueue[i])->count = 0;
          totalTellerServiceTime[i]=0.0;
          totalTellerIdleTime[i]=0.0;
     }
     for(int i=0; i<noofcustomers; i++){
          float k = (float)rand();
          float* arrivalTime = (float*)malloc(sizeof(float));
          *arrivalTime = simulationTime * k/(float)RAND_MAX;
          timing[i]=*arrivalTime;
     }

     sort(timing,0,noofcustomers-1);

     for(int i=0; i<noofcustomers; i++){
          addevent(&list,timing[i],0.0,1,0,0.0,timing[i],0.0,i);
     }

     for(int i=0; i<nooftellers; i++){
          int k1 = rand()%600;
          k1=k1+1;
          float k = ((float)k1)/60;
          addevent(&list,0.0,0.0,4,i,k,(clockml+k),0.0,-1);
     }
     printf("\n\n");
     printf("\t**************************************\n");
     printf("\t*  SIMULATION OF MULTI LINE SERVICE  *\n");
     printf("\t**************************************\n\n");
     // printf("<-----------INITIALLY----------->\n");
     // printEventQueue(&list);
     // printf("<-------------QUEUE----------->\n");
     // for(int i=0; i<nooftellers; i++){
     //      printCustomerQueue(&(tellerQueue[i]),i);
     // }
     // printf("<-------------QUEUE----------->\n");
     // printf("\nTIME = %f\n\n", clockml);
     while(clockml<=simulationTime){
          // printf("\n---------------------------------------------------------------------------------------\n\n");
          // printEventQueue(&list);
          // printf("\n");
          struct Event* event = rmvEvent(&list);
          if(event->action==1){
               int a = smallestline(tellerQueue,nooftellers);
               addcustomer(&(tellerQueue[a]),event->arrivalTime,event->customerno);
               clockml = event->arrivalTime;
          }
          else if(event->action==2){
               clockml = event->time;
               float waittime = (event->completionTime - event->arrivalTime);
               if(waittime>maxwaittime){
                    maxwaittime=waittime;
               }
               totaltime = totaltime + waittime;
               noofcustomerserved++;
               printf("\t*************************************************\n");
               printf("\t*\tCustomer %d arrivalTime: %f\t*\n", event->customerno, event->arrivalTime);
               printf("\t*\tCustomer %d serviceTime: %f\t*\n", event->customerno, event->serviceTime);
               printf("\t*\tCustomer %d completionTime: %f\t*\n",event->customerno, event->completionTime);
               printf("\t*************************************************\n");
          }
          else if(event->action==3){
               int k1 = rand()%150;
               k1=k1+1;
               float k = ((float)k1)/60;
               // printf("$$$%f\n", k);
               totalTellerIdleTime[event->tellerno] += k;
               addevent(&list,0.0,0.0,4,event->tellerno,k,clockml+k,clockml+k,-1);
               clockml = event->time;
          }
          else if(event->action==4){
               float* serviceTime = (float*)malloc(sizeof(float));
               *serviceTime = 2.0*averageServiceTime*((float)rand())/((float)(RAND_MAX));
               float completionTime=event->arrivalTime + *serviceTime;
               struct Customer* customer = rmvCustomer(&(tellerQueue[event->tellerno]));
               if(customer==NULL){
                    int k1 = rand()%150;
                    k1=k1+1;
                    float k = ((float)k1)/60;
                    clockml = event->time;
                    // printf("===%f\n", k);
                    addevent(&list,0.0,0.0,4,event->tellerno,k,clockml+k,clockml+k,-1);
                    totalTellerIdleTime[event->tellerno] += k;
               }
               else{
                    clockml= event->time;
                    addevent(&list,customer->arrivalTime,*serviceTime,2,event->tellerno,0.0,clockml+*serviceTime,clockml+*serviceTime,customer->customerno);
                    addevent(&list,event->arrivalTime,*serviceTime,3,event->tellerno,0.0,clockml+*serviceTime,clockml+*serviceTime,-1);
                    totalTellerServiceTime[event->tellerno] += *serviceTime;
               }
          }
          // printf("\n");
          // printf("<-------------QUEUE----------->\n");
          // for(int i=0; i<nooftellers; i++){
          //      printCustomerQueue(&(tellerQueue[i]),i);
          // }
          // printf("<-------------QUEUE----------->\n");
          // printf("\nTIME = %f\n", clockml);
     }

     float averageTimeofCustomers = totaltime / ((float)noofcustomers);

     printf("\n------------------------------STATISTICS------------------------------\n");
     printf("\nNO OF CUSTOMERS SERVED: %d\n", noofcustomerserved);
     printf("TOTAL TIME REQUIRED TO SERVE ALL CUSTOMERS: %f mins\n", totaltime);
     printf("NO OF TELLERS: %d\n", nooftellers);
     printf("QUEUING TYPE: MULTILINE(ONE PER TELLER)\n");
     printf("AVERAGE TIME SPENT BY A CUSTOMER: %f mins\n", averageTimeofCustomers);
     printf("MAXIMUM WAITING TIME BY ANY CUSTOMER: %f mins\n", maxwaittime);
     printf("TOTAL TIME SPENT BY TELLERS(in mins):\n");
     printf("NO\tSERVICE TIME\tIDLE TIME\n");
     for(int i=0; i<nooftellers; i++){
          printf("%d\t%f\t%f\n",i,totalTellerServiceTime[i],totalTellerIdleTime[i]);
     }
     printf("----------------------------------------------------------------------\n");
}
float simulateSingleLine(struct EventQueue* list,int noofcustomers, int nooftellers, float simulationTime, float averageServiceTime){
     srand ( time(NULL) );
     float clocksl=0.0;
     struct tellerQueue* tellerQueue=(struct tellerQueue*)malloc(sizeof(struct tellerQueue));;

     float timing[noofcustomers];
     float totaltime=0.0;
     float maxwaittime = 0.0;
     float totalTellerServiceTime[nooftellers];
     float totalTellerIdleTime[nooftellers];
     int noofcustomerserved = 0;

     for(int i=0; i<noofcustomers; i++){
          float k = (float)rand();
          float* arrivalTime = (float*)malloc(sizeof(float));
          *arrivalTime = simulationTime * k/(float)RAND_MAX;
          timing[i]=*arrivalTime;
     }

     sort(timing,0,noofcustomers-1);

     for(int i=0; i<noofcustomers; i++){
          addevent(&list,timing[i],0.0,1,0,0.0,timing[i],0.0,i);
     }

     for(int i=0; i<nooftellers; i++){
          int k1 = rand()%600;
          k1=k1+1;
          float k = ((float)k1)/60;
          addevent(&list,0.0,0.0,4,i,k,k,0.0,-1);
          totalTellerIdleTime[i]=0.0;
          totalTellerServiceTime[i]=0.0;
     }
     printf("\n\n");
     printf("\t***************************************\n");
     printf("\t*  SIMULATION OF SINGLE LINE SERVICE  *\n");
     printf("\t***************************************\n\n");
     // printf("<-----------INITIALLY----------->\n");
     // printEventQueue(&list);
     //
     // printf("<-------------QUEUE----------->\n");
     // printCustomerQueueSingleLine(&(tellerQueue));
     // printf("<-------------QUEUE----------->\n");
     // printf("\nTIME = %f\n\n", clocksl);
     while(!isempty(&list) && clocksl<=simulationTime){
          // printf("\n---------------------------------------------------------------------------------------\n\n");
          // printEventQueue(&list);
          // printf("\n");
          struct Event* event = rmvEvent(&list);
          if(event->action == 1){
               addcustomer(&(tellerQueue),event->arrivalTime,event->customerno);
               clocksl = event->arrivalTime;
          }
          else if(event->action == 2){
               clocksl = event->time;
               float waittime = (event->completionTime - event->arrivalTime);
               if(waittime>maxwaittime){
                    maxwaittime=waittime;
               }
               totaltime = totaltime + waittime;
               noofcustomerserved++;
               printf("\t*************************************************\n");
               printf("\t*\tCustomer %d arrivalTime: %f\t*\n", event->customerno, event->arrivalTime);
               printf("\t*\tCustomer %d serviceTime: %f\t*\n", event->customerno, event->serviceTime);
               printf("\t*\tCustomer %d completionTime: %f\t*\n",event->customerno, event->completionTime);
               printf("\t*************************************************\n");
          }
          else if(event->action == 3){
               int k1 = rand()%150;
               k1=k1+1;
               float k = ((float)k1)/60;
               // printf("$$$%f\n", k);
               totalTellerIdleTime[event->tellerno] += k;
               addevent(&list,0.0,0.0,4,event->tellerno,k,clocksl+k,clocksl+k,-1);
               clocksl = event->time;
          }
          else if(event->action == 4){
               float* serviceTime = (float*)malloc(sizeof(float));
               *serviceTime = 2.0*averageServiceTime*((float)rand())/((float)(RAND_MAX));
               float completionTime=event->arrivalTime + *serviceTime;
               struct Customer* customer = rmvCustomer(&(tellerQueue));
               if(customer==NULL){
                    int k1 = rand()%150;
                    k1=k1+1;
                    float k = ((float)k1)/60;
                    clocksl = event->time;
                    // printf("===%f\n", k);
                    addevent(&list,0.0,0.0,4,event->tellerno,k,clocksl+k,clocksl+k,-1);
                    totalTellerIdleTime[event->tellerno] += k;
               }
               else{
                    clocksl= event->time;
                    addevent(&list,customer->arrivalTime,*serviceTime,2,event->tellerno,0.0,clocksl+*serviceTime,clocksl+*serviceTime,customer->customerno);
                    addevent(&list,event->arrivalTime,*serviceTime,3,event->tellerno,0.0,clocksl+*serviceTime,clocksl+*serviceTime,-1);
                    totalTellerServiceTime[event->tellerno] += *serviceTime;
               }
          }
          // printf("\n");
          // printf("<-------------QUEUE----------->\n");
          // printCustomerQueueSingleLine(&(tellerQueue));
          // printf("<-------------QUEUE----------->\n");
          // printf("\nTIME = %f\n", clocksl);
     }
     float averageTimeofCustomers = totaltime / ((float)noofcustomers);

     printf("\n------------------------------STATISTICS------------------------------\n");
     printf("\nNO OF CUSTOMERS SERVED: %d\n", noofcustomerserved);
     printf("TOTAL TIME REQUIRED TO SERVE ALL CUSTOMERS: %f mins\n", totaltime);
     printf("NO OF TELLERS: %d\n", nooftellers);
     printf("QUEUING TYPE: COMMON LINE\n");
     printf("AVERAGE TIME SPENT BY A CUSTOMER: %f mins\n", averageTimeofCustomers);
     printf("MAXIMUM WAITING TIME BY ANY CUSTOMER: %f mins\n", maxwaittime);
     printf("TOTAL TIME SPENT BY TELLERS(in mins):\n");
     printf("NO\tSERVICE TIME\tIDLE TIME\n");
     for(int i=0; i<nooftellers; i++){
          printf("%d\t%f\t%f\n",i,totalTellerServiceTime[i],totalTellerIdleTime[i]);
     }
     printf("----------------------------------------------------------------------\n");

     return averageTimeofCustomers;
}
int main(int argc, char* argv[]){
     struct EventQueue* list= NULL;
     list = (struct EventQueue*)malloc(sizeof(struct EventQueue));
     struct EventQueue* list1= NULL;
     list1 = (struct EventQueue*)malloc(sizeof(struct EventQueue));
     int noofcustomers=atoi(argv[1]);
     int noofcustomers1=noofcustomers;
     int nooftellers=atoi(argv[2]);
     int nooftellers1=nooftellers;
     float simulationTime=atof(argv[3]);
     float simulationTime1=simulationTime;
     float averageServiceTime=atof(argv[4]);
     float averageServiceTime1=averageServiceTime;

     // printf("noof customers = %d\n", noofcustomers);
     // printf("tellers = %d\n", nooftellers);
     // printf("simulation time = %f\n", simulationTime);
     // printf("avg = %f\n", averageServiceTime);

     printf("----------------------------------------------------------------------\n");
     simulateMultiLine(list,noofcustomers,nooftellers,simulationTime,averageServiceTime);
     printf("----------------------------------------------------------------------\n");
     simulateSingleLine(list1, noofcustomers1, nooftellers1, simulationTime1, averageServiceTime1);
     printf("----------------------------------------------------------------------\n");



     //GNUPLOT

     int nooftestcase = 10;

     float averageTimeofCustomers[nooftestcase];

     for(int i=1; i<=nooftestcase; i++){
          struct EventQueue* list2= NULL;
          list2 = (struct EventQueue*)malloc(sizeof(struct EventQueue));
          averageTimeofCustomers[i-1]=simulateSingleLine(list2,10,i,50,2.3);
     }
     // for(int i=1; i<=nooftestcase; i++){
     //      printf("%f\n",averageTimeofCustomers[i-1]);
     // }

     char* commandsForGnuplot[]={
               "set boxwidth 1",
               "set xlabel \"No of Tellers--->\"",
               "set ylabel \"Average time a customers spent in bank(in mins)---->\"",
               "set title \"Analysis of time spent by customer in bank \"",
               "set style fill solid border -1",
               "set style data histograms",
               "plot \'./others/data.txt\' using 2:xtic(1) title \'Time spent by customers in bank\'",
               "set term pngcairo",
               "set output \"./output/graph.png\"",
               "set terminal png",
               "replot",
               "set output"
          };

     FILE * temp = fopen("./others/data.txt", "w");
     FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
     for(int i=0; i<nooftestcase; i++){
          fprintf(temp, "%d %f\n",(i+1),averageTimeofCustomers[i]);
     }
     for(int i=0; i<12; i++){
     	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
	}

     return 0;
}