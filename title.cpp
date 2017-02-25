//Colin Aslett, Shunting Yard Algorithm, C++ Period 07
//http://www.cprogramming.com/tutorial/lesson15.html
//http://www.sanfoundry.com/cpp-program-implement-stack-linked-list/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
struct Node{
  char fir[1];
  Node* next;
  int pre;//precedence
};
Node* head = NULL;
void pop(char* ch,int a, char* as);
void push(char* ch, int a, char* as);
int main(){
  char input[100];
  cout << "Enter a expression" << endl;
  cin >> input;
  bool kg = false;
  int i = 0;
  size_t length = strlen(input);
  cout << "length of input: " << length << endl;
  char ans[length];
  ans[0] = '\0';
  while(kg == false){
    push(input,i,ans);
    i++;
    if(i == length){
      if(i == strlen(input)){
	Node* el = head;
	while(head != NULL){
	  size_t leng = strlen(input);//input queue
	  size_t opp = strlen(ans);//output queue
	  if(el->next != NULL){
	    el = el->next;
	    cout << "searching" << endl;
	  }
	  if(el->next == NULL){
	    ans[opp] = el->fir[0];
	    ans[opp+1] = '\0';
	    cout << "final queue: " << ans << endl;
	    //el = head;
	  }
	}
      }
      kg = true;
    }
  }
  return 0;
}
void push(char* ch, int a, char* as){
  if(isdigit(ch[a])){
    cout << "digit" << endl;
    size_t len = strlen(as);
    as[len] = ch[a];
    as[len+1] = '\0';
    cout << "output queue: " << as << endl;
  }
  if(ch[a] == '-' || ch[a] == '+' || ch[a] == '*' || ch[a] == '/' || ch[a] == '^'){
    /*
    Node* current = head;
    if(current == NULL){
      head = new Node;
      head->fir[0] = ch[a];
      cout << "operand" << endl;
    }
    else{
      while(current->next != NULL){
	current = current->next;
      }
      current->next = new Node;
      current->next->fir[0] = ch[a];
      cout << "second phase operator" << current->fir[0] << endl;
    }
    */
    int prec;//precedence
    if(ch[a] == '-'){
      prec = 2;
    }
    if(ch[a] == '+'){
      prec = 2;
    }
    if(ch[a] == '/'){
      prec = 3;
    }
    if(ch[a] == '*'){
      prec = 3;
    }
    if(ch[a] == '^'){
      prec = 4;
    }
    //check for popping
    bool con = true;
    Node* check;
    while(con == true){
      check = head;
      if(check != NULL){
	while(check->next != NULL){
	  check = check->next;
	}
	if(check->pre > prec || check->pre == prec){
	  //con = true; stays true
	  pop(ch,a,as);
	  con = false;
	  cout << "lower precedence" << endl;
	}
	else{
	  con = false;
	  cout << "higher precedence" << endl;
	}
      }
      else{
	con = false;
	break;
      }
    }
    //node setting
    Node* current = head;
    if(current == NULL){
      head = new Node;
      head->next = NULL;
      head->fir[0] = ch[a];
      head->pre = prec;
      cout << "first operand!" << endl;
    }
    else{
      while(current->next != NULL){
	current = current->next;
      }
      current->next = new Node;
      current = current->next;
      current->next = NULL;
      current->fir[0] = ch[a];
      current->pre = prec;
      cout << "another operand" << endl;
    }
    //printing out the stack
    Node* prin = head;
    while(prin != NULL){
      cout << prin->fir[0] << " , " << prin->pre << endl;
      prin = prin->next;
    }
    //clearing out the stack
  }
}
void pop(char* ch, int a, char* as){
  Node* current = head;
  size_t len = strlen(as);
  while(current->next != NULL){
    current = current->next;
  }
  as[len] = current->fir[0];
  as[len+1] = '\0';
  current = NULL;
  delete current;
  cout << "UPDATED queue: " << as << endl;
}
