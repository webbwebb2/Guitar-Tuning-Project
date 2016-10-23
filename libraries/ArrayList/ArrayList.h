/*
 * ArrayList.h - Library for Arduino (Uno) ArrayList
 *
 * The implementation is based on Linked List. The naming system mimics Java
 * style, although not all methods are available except those most common ones.
 *
 * Created by Chonghua Xue, October 19, 2016
 */

#ifndef ArrayList_h
#define ArrayList_h

class ArrayList {
  public:
    ArrayList(const char);   // constructor
    ~ArrayList(void);        // destructor
    int add(void*);      // append to ArrayList
    int print();         // output to Serial.begin(9600)

  private:
  	void** hptr;          // pointer to the head of ArrayList
  	char dype;           // # of bytes per element
};

#endif