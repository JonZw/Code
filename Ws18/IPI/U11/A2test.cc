#include <iostream>

class A {
public:
  void a(){
    std::cout<<"a() in A"<<std::endl;
  }
  virtual void va() = 0;
  virtual void a(int n){
    std::cout<<"virtual void a(int n) in A"<<std::endl;
  }
private:
  void c(){
    std::cout<<"void c() in A"<<std::endl;
  }
};


class B: public A {
public:
  void b(){
    std::cout<<"void b() in B"<<std::endl;
  }
  virtual void vb(){
    std::cout<<"virtual void vb() in B"<<std::endl;
  }
  void a(double d){
    std::cout<<"void a(double d) in B"<<std::endl;
  }
  void a(int i){
    std::cout<<"void a(int i) in B"<<std::endl;
  }
  virtual void va(){
    std::cout<<"virtual void va() in B"<<std::endl;
  }
};

class C: public B {
public:
virtual void c(){
  std::cout<<"virtual void c() in C"<<std::endl;
}
void a(float){
  std::cout<<"void a(float) in C"<<std::endl;
}
virtual void a(){
  std::cout<<"virtual void a() in C"<<std::endl;
}
virtual void va(){
  std::cout<<"virtual void va() in C"<<std::endl;
}
};

int main()
{
//A a;
B b;
C c;
A* pa=&b;
B* pb=&c;
float x = 1.2;
//pa->a();
//pa->va();
//pa->a(1);
  //pa->c();
  //pa->b();
  //pa->vb();
pa->a(x);
  //pb->a();
//pb->va();
//pb->a(1);
  //pb->c();
//pb->b();
//pb->vb();
//pb->a(x);
//pa = &c;
//pa->a();
//pa->va();
//pa->a(1);
  //pa->c();
  //pa->b();
  //pa->vb();
//pa->a(x);
}
