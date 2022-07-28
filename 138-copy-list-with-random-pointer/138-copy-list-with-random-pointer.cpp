/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        
        // Two Pointers Approach
        
        Node* temp = head;
        
        while(temp)
        {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        // add the copy nodes in betwwen the original list
        Node* dummy = head;

        //First Pass : save the random pointers
        while(dummy)
        {
            if(dummy->random)
            {
                dummy->next->random = dummy->random->next;
            }
            dummy = dummy->next->next;
        } 
        
        //Second Pass : save the next pointers in the copied linked list
        //Note : Return the original addresses of the original linked list
        Node* original = NULL;
        Node* temp1 = NULL;
        Node* temp2 = NULL;
        Node* copy = NULL;
        
        while(head)
        {
            if(original==NULL)
            {
                original = head;
                copy = head->next;
                temp1 = head;
                temp2 = head->next;
            }else{
                 temp1->next = head;
                 temp1 = temp1->next;
                 temp2->next = head->next;
                 temp2 = temp2->next;
            }
            head = head->next->next;
        }
        
        temp1->next = NULL;
        temp2->next = NULL;
        
        return copy;
        
    }
};