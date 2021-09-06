/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* ptr = head;
        node* prev = NULL;
        queue<node*> q;
        while(ptr){
            
            int temp = k;
            while(temp-- && ptr){
                node* cur = ptr;
                ptr = ptr->next;
                cur->next = prev;
                prev = cur;
            }
            
            q.push(prev);
            prev = NULL;
            
        }
        
        int n = q.size();
        ptr = NULL;
        if( n == 1){
            head = q.front();
            q.pop();
        }
        else if( n > 1){
            head = q.front();
            
            
            while(n--){
                if(!ptr) ptr = q.front();
                
                else ptr->next = q.front();
                q.pop();
                
                while(ptr && ptr->next){
                    ptr = ptr->next;
                }
                
            }
        }
        
        return head;
    }
};
