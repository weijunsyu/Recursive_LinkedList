#ifndef LLIST_H
#define LLIST_H

#define NDEBUG

class  LList {
   public:
      // build a list
      LList();

      // determine if the list is empty
      bool isEmpty() const;

	  // give length of list
      int length() const;

	  // insert ch at the beginning (at the front) of the linked list
      // return true if successful, false otherwise
      bool cons(char ch);

	  // append ch to the end of the linked list
      // return true if successful, false otherwise
      bool append(char ch);

	  // delete the first occurence of ch in the list
      // if the deletion happens, return true,  false otherwise
      bool remove(char ch);

	  // search ch in the list, return true if found, false otherwise
      bool found(char ch) const;

	  // if the list is empty,  hasFirst is set to false and the character '\0'
      // is returned, otherwise it returns the first character of the list and
      // hasFirst is set to true
      char getFirst(bool& hasFirst) const;

	  // reverses the list, the original list is mutated
      void reverse();

	  // print the list to standard output started with a  '[' and finished
      // with a ']' followed by an end-of-line
      void print() const;


      // copy constructor
      LList(const LList& list);

	  // destructor
      ~LList();

	  //assignment operator
      LList& operator = (const LList& rtSide);


   private:
      struct Node {
         char item;
         Node* next;
      };

      // pointer to the linked list
      Node* head;

      // get the length of the list p
      static int length(Node *p);

	  // construct a new Node
	  static Node* cons(char ch, Node *p);

	  // recursive helper function for the append function
	  static Node* recAppend(char ch, Node* p);

	  // recursive helper function for print
	  static void recPrint(const Node* p);

	  // recursive helper function for remove
	  static Node* recRemove(char ch, Node* p, bool &flag);

	  // recursive helper function for destructor
	  static void recDestruct(Node* &p);

	  //recurisve helper function for deep copying of list
	  static Node* recCopy(Node* p);

    //recursive helper function for found
	  static bool recFound(char ch, Node* p);
};
#endif
