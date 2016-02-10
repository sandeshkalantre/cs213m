#include "stack.hpp"
#include "stack.cpp"
#include <iostream>

using namespace std;

int main() {
  stack<int> *s = new stack<int>();

  int n_ops;
  cin >> n_ops;
  while(n_ops) {
    n_ops--;

    char op;
    cin >> op;

    // push
    if (op == 'p') {
      int arg;
      cin >> arg;
      s->push(arg);
    }
    // top
    else if (op == 't') {
      int elem;
      s->top(&elem);
      cout << elem << endl;
    }
    // pop
    else if (op == 'o') {
      s->pop();
    }
    // size
    else if (op == 's') {
      cout << s->size() << endl;
    }
    // dump
    else if (op == 'd') {
      stack<int> to_print = *s;
      int elem;
      while (to_print.size()) {
        to_print.top(&elem);
        cout << elem << ' ';
        to_print.pop();
      }
      cout << '_' << endl;
    }
  }
}
