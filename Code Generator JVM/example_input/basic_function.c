int foo(int a, float b);
int foo(int a, float b) {
   a += 6;
   return a;
}

void lol(int a) {
    print(a);
	return;
}

void main(){
  int a ;
   a = foo(a, 5.3);
   lol(a);
   return;
}
