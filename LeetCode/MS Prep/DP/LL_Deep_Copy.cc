class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *ptr = head;          //pointed to the head of LL
        Node *clone = new Node(0); // a dumy node for the copy LL
        Node *t = clone;           // a pointer to the head of the copy

        map<Node *, Node *> node_map;

        //First pass - Only link the Nodes with Next pointer
        //Do nothing with thr Random pointers
        while (ptr != nullptr) //traversing the LL
        {
            Node *curr = new Node(ptr->val); //New node for the copy

            node_map[ptr] = curr;

            t->next = curr;
            t = t->next;
            ptr = ptr->next;
        }
        ptr = head;
        t = clone->next;

        while (ptr != nullptr)
        {
            node_map[ptr]->random = node_map[ptr->random];
            ptr = ptr->next;
        }

        return clone->next;
    }
};
