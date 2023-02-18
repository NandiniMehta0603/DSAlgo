{
   // Write your code here
    if(head==NULL){
      return NULL;
  }

  unordered_map<int,bool>visited;
    Node* prev = head;
    Node* curr = head->next;
    
    visited[prev->data] = true;
    
    while(curr!=NULL){
        if(visited[curr->data] == true){
            prev->next = curr-> next;
            delete(curr);
        }
        else{
            visited[curr->data] = true;
            prev = prev->next;
        }
        curr = prev->next;
    }
    return head;
}
