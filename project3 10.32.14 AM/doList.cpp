
using namespace std;
class doList{

  struct node {
    float speed;
    float fuelUsage;
    node* prev; // Pointer to previous node in DLL
    node* next; // Pointer to next node in DLL

    node(float s,float f){
      prev = NULL;
      next = NULL;
      speed = s;
      fuelUsage = f;
    }
  };



  public:
    doList(float avgSpeed[],float fuelEfficiency[],int size){
      //mergeSort(avgSpeed, fuelEfficiency,0,size-1);
      array = new node*[size];
      int i=0;
      for(i=0;i<size;i++){
        node* n=new node(avgSpeed[i],fuelEfficiency[i]);
        array[i]=n;
        //cout<<array[i]->speed<<"\t"<<array[i]->fuelUsage<<endl;
        if(i==0){
          n->prev = NULL;
          head = n;
          tail = n;
        }
        else{
        n->prev = tail;
        tail->next = n;
        tail = n;
        }
      }
      count=size;
      tail->next = NULL;

      mergeSort(&head);
      domination(head);
    }
    void out(char mode){
        display(head,mode);
        cout<<endl;
    }
    void display(node* head,char mode){
	       node*temp= head;

      if(mode=='a'){
        float speed[1000];
        int i=0;
        int j=0;
        float fuel[1000];
        while(head!=NULL){
               temp = head;
               head = head->next; //move to next node
        }
        while(temp!=NULL){
          speed[i]=temp->speed;
          fuel[i]=temp->fuelUsage;
          temp=temp->prev; //move to next node
          i++;
        }
        for(j=i-1;j>=0;j--){
          if(j==0){
            cout<<speed[j];
          }
          else{
          cout<<speed[j]<<",\t";
        }}
        cout<<endl;
        for(j=i-1;j>=0;j--){
          if(j==0){
            cout<<fuel[j];
          }
          else
            cout<<fuel[j]<<",\t";
        }


      }
      if(mode=='d'){
        while(head!=NULL){
               temp = head;
               head = head->next; //move to next node
        }
        node* temp2 = temp;
        while(temp2!=NULL){
          if(temp2->prev ==NULL)
            cout<<temp2->speed;
          else
            cout<<temp2->speed<<",\t";
          temp2=temp2->prev; //move to next node
        }
        cout<<endl;
        while(temp!=NULL){
          if(temp->prev ==NULL)
            cout<<temp->fuelUsage;
          else
            cout<<temp->fuelUsage<<",\t";
          temp=temp->prev; //move to next node
        }

      }
    }

    void out(int runs,char mode){
      display(head,mode);
      cout<<endl;
      }

    int insert(float speed,float fuelUsage){
      //if adding the value overflows array, double array size and copy
      return 0;
    }

    void increase_speed(int index,float speedIncrease){
      node *temp = array[index];
      temp->speed += speedIncrease;
      mergeSort(&head);
      domination(head);
    }
    void decrease_fuel(int index,float fuelDecrease){
      node *temp = array[index];
      temp->fuelUsage -=fuelDecrease;

      domination(head);
    }

    void mergeSort(node** head){
  	node* list1;
  	node* list2;
  	/* Base case -- length 0 or 1 */
  	if ((*head == NULL) || ((*head)->next == NULL))
  	{
    	return;
  	}

  	// Split list(head) into 'list1' and 'list2' sublists
  	splitLL(*head, &list1, &list2);

  	/* Recursively sort the sublists */
  	mergeSort(&list1);
  	mergeSort(&list2);
  	//merge the two sorted lists together
  	*head = mergeSortedLists(list1, list2);
}
//Merge the two sorted lists
node* mergeSortedLists(node* list1, node* list2){
  //display(&list1);
  //cout<<(list1->data);
  node* result = NULL;

  /* Base cases */
  if (list1 == NULL)
     return(list2);
  else if (list2==NULL)
     return(list1);

  /* Pick either list1 or list2, and recur */
  if (list1->speed <= list2->speed)
  {
    list1->next = mergeSortedLists(list1->next,list2);
    list1->next->prev = list1;
    list1->prev = NULL;
    return list1;
  }
  else
  {
    list2->next = mergeSortedLists(list1,list2->next);
    list2->next->prev = list2;
    list2->prev = NULL;
    return list2;
  }
}
//split the nodes into two halves
void splitLL(node* head, node** list1, node** list2){
  node* fast;
  node* slow;
  if (head==NULL || head->next==NULL)
  {
    /* length < 2 cases */
    *list1 = head;
    *list2 = NULL;
  }
  else
  {
    slow = head;
    fast = head->next;

    // Move 'fast' two nodes, and move 'slow' one node //
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    *list1 = head;
    *list2 = slow->next;
    slow->next = NULL;
  }
}

    void domination(node* head){

      node* temp = head;
      int flag=0;
      int fuel;
      while(head!=NULL){
             temp = head;
             head = head->next; //move to next node
      }
        while(temp->prev!=NULL){
          if(temp->prev == NULL){ //last node
            break;
          }
          node* dum = temp;
          fuel = temp->fuelUsage;

          flag=0;
          while(flag!=1){
          while(fuel <= dum->prev->fuelUsage){
            dum = dum->prev;
            if(dum->prev == NULL){
              flag=1;
              break;
            }
          }
          flag=1;
        }

          temp->prev = dum->prev;
          if(dum->prev!=NULL){
            temp->prev = dum->prev;
          }
          else{break;}
          temp = temp->prev;
        }
    }








private:
  node** array;
  node* head;
  node* tail;
  node* n;
  int count;






};
