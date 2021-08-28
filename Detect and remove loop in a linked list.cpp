class Solution
{
    
    public:
    //detect a loop
    bool detloop(Node *head,Node *slow,Node *fast)
    {
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                return true;
                break;
            }
        }
        
        return false;
    }
    
    //Function to remove a loop in the linked list.
    
    /*
    GYAAN
    
    ab agar loop present hai to dono mese kisi bhi ek pointer ko waaapis head pe laao
    without changing other. ab dono ko ek ek karke aage karo and jab dono pointers 
    kisi ek node ki taraf point are to vo hai loop ka entry point!!!!
    
    to remove cycle jo loop ke andar pointer tha jisko cheda nhi tha usko NULL point karwaao
    */
    void removeLoop(Node* head)
    {
        Node *slow=head;
        Node *fast=head;
        
        //slow and fast ki positions ko laaya baraabar se
       while(fast!=NULL && slow!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                break;
            }
        }
        //agar loop head par hi hai to maa chud jaaygi
        //aise waqt me head ko aage badhao
        if(slow==head)
        {
            //philaal slow==head hai to head ko aage sarkhaao
            fast=fast->next;
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else if(slow==fast){
        fast = head;
        
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next=NULL;
        }
    }
};
