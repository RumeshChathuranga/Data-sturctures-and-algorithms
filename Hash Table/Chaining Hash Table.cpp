/*
An implementation of a LinkedList has been provided to you in the given answer template.

Complete the following functions using the given instructions:

hashfunc: Hash a given username by obtaining the sum of the ASCII values of the characters of the username. 
You may use your function from the previous question.

insert: Hash a given username using hashfunc and insert the password. 
Return 0 if the insertion was successful and 1 if it failed.

hash_lookup: Hash a given username using hashfunc and find its password. 
Use the search function of the LinkedList struct to print the password. 
Return 0 if the hash exists in the Hashtable or 1 if not.
*/


#include <iostream>
using namespace std;

struct Node
{
    string user_name;
    string password;
    Node *link;
};

struct LinkedList
{

    Node *head = NULL;
    Node *tail = NULL;

    int length = 0;

    void insert(string user_name, string password)
    {
        if (head == NULL)
        {
            Node *temp;
            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;

            temp->link = NULL;
            head = temp;
            length++;
        }
        else
        {
            Node *temp;
            Node *tail;

            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;
            temp->link = NULL;
            tail = head;
            while (true)
            {

                if (tail->link == NULL)
                {
                    break;
                }
                else
                {
                    tail = tail->link;
                }
            }
            tail->link = temp;
            length++;
        }
    }

    void search(string user_name)
    {
        Node *temp = head;
        for (int i = 0; i < length; i++)
        {
            if (temp->user_name == user_name)
            {
                cout << "Password: " << temp->password << "\n";
                break;
            }
            else
            {
                temp = temp->link;
            }
        }
    }

    void print_list()
    {
        if (head == NULL)
        {
            cout << "[]" << endl;
        }
        else
        {
            Node *temp = head;
            cout << "[";
            while (temp != NULL)
            {
                cout << temp->user_name << ", ";
                temp = temp->link;
            }
            cout << "]" << endl;
        }
    }
};

struct HashTable
{
    int MAX_LENGTH = 3;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList *passwords = new LinkedList[MAX_LENGTH];
    bool isFull()
    {
        bool full = true;
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            if (passwords[i].head == NULL)
            {
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name)
    {
        int sum = 0;
        int hash = 0;
        // <--- ADD YOUR CODE HERE --->
        int length = user_name.size();
        for (int i = 0; i < length; i++){
            sum += int(user_name[i]);
        }
        hash = sum % MAX_LENGTH;
        return hash;
    }
    bool is_slot_empty(int hash)
    {
        bool empty;
        if (passwords[hash].head == NULL)
        {
            empty = true;
        }
        else
        {
            empty = false;
        }
        return empty;
    }
    int insert(string user_name, string user_password)
    {
        int hash;
        // <--- ADD YOUR CODE HERE --->
        hash = hashfunc(user_name);
        //checking whether the length of hash chain is less than maximum length
        if (passwords[hash].length <= MAX_CHAIN_LENGTH){
            passwords[hash].insert(user_name, user_password);
            return 0;
            
        }else{
            return 1;
        }
        
    }
    void print_hashtable()
    {
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            cout << "[" << i << "]-->";
            passwords[i].print_list();
        }
    }
    int hash_lookup(string user_name)
    {
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);

        // <--- ADD YOUR CODE HERE --->
        if (empty){
            return 1; //not found
        }
        Node *temp = passwords[hash].head;
        while (temp != NULL)
        {
            if (temp->user_name == user_name){
                
                cout<<"Password: "<<temp-> password<< "\n";
                return 0; //we found
            }
            temp = temp->link;
        }
        
        return 1; //not found
    }
};

int main()
{
    HashTable *hashtbl = new HashTable;
    cout << hashtbl->isFull() << "\n";

    int command = 0;
    string user_name;
    string password;
    while (command != -1)
    {
        /* code */
        cin >> command;
        switch (command)
        {
        case 1:
            /* insert the new item*/
            cin >> user_name;
            cin >> password;
            cout << "Inserting " << user_name << "...\n";
            cout << (hashtbl->insert(user_name, password) ? "Failed" : "Succeeded") << "\n";
            break;
        case 2:
            /* hash lookup password*/
            cin >> user_name;
            cout << "Looking up " << user_name << "...\n";
            cout << (hashtbl->hash_lookup(user_name) ? "Not found" : "Found") << "\n";
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:
            break;
        }
    }
    return 0;
}
