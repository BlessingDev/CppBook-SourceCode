 // smartlist.cpp
 
 #include <iostream>
 #include <memory>
 
 template <typename T>
 class LList {
     //  An object that holds an element in a linked list.  This type is local 
     //  to the LList class and inaccessible to outside this class.
     struct Node {
         T data;                      //  A data element of the list
         std::shared_ptr<Node> next;  //  The node that follows this one in the list
         //  Constructor
         Node(const T& d): data(d), next(nullptr) {
             std::cout << "Created node with value " << data << '\n';
         }
         ~Node() {
             std::cout << "Destroyed node with value " << data << '\n';
         }
     };
  
     std::shared_ptr<Node> head;  //  Points to the first item in the list
  
 public:
     // The constructor makes an initially empty list
     LList(): head(nullptr) {
         std::cout << "Created a linked list object\n";
     }
 
     // The destructor frees up the memory held by the list
     ~LList() {
         //clear();  //  Deallocate space held by the list nodes
         std::cout << "Destroyed a linked list object\n";
     }
 
     // Inserts value onto the back of the list.  
     // value is the element to insert.
     void insert(const T& value) {
         if (!head)
             head = std::make_shared<Node>(value);
         else {
             auto p = head;
             while (p->next)
                 p = p->next;  // Move to end of list
             p->next = std::make_shared<Node>(value);
         }
     }
 
     // Prints the contents of the linked list of integers.
     void print() const {
         for (auto p = head; p; p = p->next)
             std::cout << p->data << " ";  //  Print current node's data
         std::cout << '\n';
     }
 };
 
 void test() {
     LList<int> list; 
     for (int i = 0; i < 10; i++)
         list.insert(i);
     //list.print();
 }
 
 int main() {
     for (int i = 0; i < 10; i++)
         test();
 }

